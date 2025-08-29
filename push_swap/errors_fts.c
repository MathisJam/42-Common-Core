/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_fts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:45:30 by mjameau           #+#    #+#             */
/*   Updated: 2024/07/08 13:44:13 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Ici les fonctions d'erreurs qu'on appelle dans la fonction
d'initialisation de la stack
Il y a aussi 2 fonctions pour free en cas d'erreur,
une fonction qui va free la stack et nous permettre
d'ecrire le message d'erreur
et une fonction qui va free tout les arguments*/

#include "push_swap.h"

void	error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*cur;

	if (!stack)
		return ;
	cur = *stack;
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	*stack = NULL;
}

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (!argv || !*argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

int	error_syntax(char *str_nb)
{
	if (!(*str_nb == '+' || *str_nb == '-' || (*str_nb >= '0'
				&& *str_nb <= '9')))
		return (1);
	if ((*str_nb == '+' || *str_nb == '-') && !(str_nb[1] >= '0'
			&& str_nb[1] <= '9'))
		return (1);
	return (0);
}

int	error_repetition(t_stack_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
