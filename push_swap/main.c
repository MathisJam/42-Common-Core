/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:03:15 by mjameau           #+#    #+#             */
/*   Updated: 2024/07/08 12:26:08 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Si il n'y a qu'un seul argument alors c'est qu'il est sans doute entre
double quotes, on va utiliser split pour recuperer tout les nombres separes
par des espaces et donc nous creer des arguments */

/* On initialise la stack avec create_stack et on check si la stack est
triee ou non avec sort_stack, si c'est deja trie alors rien a faire mais
si ca ne l'est pas alors on va calculer la longueur et utiliser la fonction
la plus appropriee pour le cas.*/

/* Une fois fait, on peut free la stack ! */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split_remake(argv[1], ' ');
	create_stack(&a, argv + 1, argc == 2);
	if (!sort_stack(a))
	{
		if (remake_lstsize(a) == 2)
			sa(&a, false);
		else if (remake_lstsize(a) == 3)
			three_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
