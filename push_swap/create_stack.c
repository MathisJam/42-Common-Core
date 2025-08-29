/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:52:55 by mjameau           #+#    #+#             */
/*   Updated: 2024/07/08 12:26:54 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ici on cree la stack et on met les arguments dans un atol pour
gerer les signes - et + ainsi que les overflows en les passant dans un long.
On regarde ensuite si il y a des erreurs
(repetitions,syntaxe (genre des lettres),
Si il y en a on free et si il n'y en a pas on peut
ajouter la nouvelle node n dans la stack a.
 */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

void	create_stack(t_stack_node **a, char **argv, bool flag_argc_2)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)n))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)n);
		++i;
	}
	if (flag_argc_2)
		free_matrix(argv);
}
