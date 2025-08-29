/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:59:52 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/22 12:48:15 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	atoi_skip_alpha(const char *s)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (((9 <= s[i]) && (s[i]) <= 13) || (s[i] == 32) || ft_isalpha(s[i]))
		i++;
	if ((s[i] == '+') || (s[i] == '-'))
	{
		if (s[i] == '+')
			i++;
		else
		{
			sign *= -1;
			i++;
		}
	}
	while (('0' <= s[i]) && (s[i] <= '9'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

int	count_strings(char **strings)
{
	int	count;

	count = 0;
	while (strings && strings[count])
		count++;
	return (count);
}

static int	*convert_to_int_arr(char **tab, t_data *data)
{
	int	i;
	int	count;
	int	*arr;

	i = -1;
	count = count_strings(tab);
	if (count != 3)
		err_msg("F or C is missing one value\n", data, true);
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	while (++i < count)
	{
		if (tab[i])
			arr[i] = atoi_skip_alpha(tab[i]);
		else
			arr[i] = -1;
		if (0 > arr[i] || arr[i] > 255)
			err_msg("C or F value must be between 0 and 255\n", data, true);
	}
	return (arr);
}

void	get_floor_ceiling(t_data *data)
{
	data->ceiling = convert_to_int_arr(data->c_strings, data);
	data->floor = convert_to_int_arr(data->f_strings, data);
}
