/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:43:43 by mjameau           #+#    #+#             */
/*   Updated: 2024/07/08 12:30:42 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*L'algorithme de tri,
on va utiliser les fonctions rotate en fonction du cout et de la cible,
et la fonction end_rota permet de savoir quelle rotation utiliser en fonction
de la medianne,
et sur quelle stack operer en fonction du caractere envoye en parametre
lors de l'appel de la fonction*/

/*La function move_node permet de bouger les nodes en fonction
de la cible et de la medianne, afin que les nodes de la stack B
soit push au dessus de leur cible sur la stack A */

/*Enfin, push_swap va calculer la taille de la stack,
si elle est egale a 5 alors on la passe a five_sort,
et si elle est superieure a 3 alors on push a dans b jusqu'q ce qu'il en reste 3
pour ensuite utiliser three_sort*/

#include "push_swap.h"

static void	rotate_2(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, false);
	current_pos(*a);
	current_pos(*b);
}

static void	reverse_rotate_2(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, false);
	current_pos(*a);
	current_pos(*b);
}

void	end_rota(t_stack_node **stack, t_stack_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_2(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_2(a, b, cheapest_node);
	end_rota(b, cheapest_node, 'b');
	end_rota(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest_node;
	int				a_size;

	a_size = remake_lstsize(*a);
	if (a_size == 5)
		five_sort(a, b);
	else
	{
		while (a_size-- > 3)
			pb(b, a, false);
	}
	three_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	current_pos(*a);
	smallest_node = smallest(*a);
	if (smallest_node->above_median)
		while (*a != smallest_node)
			ra(a, false);
	else
		while (*a != smallest_node)
			rra(a, false);
}
