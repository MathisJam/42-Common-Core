/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:49:57 by mjameau           #+#    #+#             */
/*   Updated: 2024/11/23 11:40:48 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static bool	is_digit(char c)
{
	return ((c >= '0' && c <= '9'));
}

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*nb;

	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error_exit("Negative values are not allowed :((");
	if (!is_digit(*str))
		error_exit("Input is not a correct digit");
	nb = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
		error_exit("Value is bigger than INT_MAX");
	return (nb);
}

static long	ft_atol(const char *str)
{
	long	nb;

	nb = 0;
	str = valid_input(str);
	while (is_digit(*str))
		nb = (nb * 10) + (*str++ - '0');
	if (nb > INT_MAX)
		error_exit("Value is bigger than INT_MAX");
	return (nb);
}

// Check si c'est bien des int
// check si pas au dessus de INT_MAX
// Check si le timestamp est correct > 60ms
void	parsing(t_data *data, char **argv)
{
	data->nb_philo = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]) * 1e3;
	data->time_to_eat = ft_atol(argv[3]) * 1e3;
	data->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (data->time_to_die < 6e4 || data->time_to_sleep < 6e4
		|| data->time_to_eat < 6e4)
		error_exit("Put timer > than 60ms...\n" C "They're not slaves..." RST);
	if (argv[5])
		data->limit_meals = ft_atol(argv[5]);
	else
		data->limit_meals = -1;
}
