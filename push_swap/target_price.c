/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_price.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:40:44 by mjameau           #+#    #+#             */
/*   Updated: 2024/07/08 12:29:24 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*la partie chiante... en gros current_pos on va creer la mediane
et checker si on se situe au dessus ou en dessous,
target_mnode va nous permettre d'assigner une target a notre node de b,
en cherchant le plus proche plus grand,
si y a pas alors on lui assigne le plus petit en target */

/*set_price on va check combien d'operations il nous faut pour
push la node de b sur a, on va regarder ca en fonction de la medianne et
de la taille de la stack*/

/*set_cheapest nous sert a trouver celle qui est la moins couteuse
suite a push_price*/

/*init nodes va nous permettre de donner toutes ses valeurs
pour permettre le push, la cible, le cout, la position etc*/

#include "push_swap.h"

void	current_pos(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = remake_lstsize(stack) / 2;
	while (stack)
	{
		stack->current_pos = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_a;
	t_stack_node	*target_node;
	long			best_match;

	target_node = smallest(a);
	while (b)
	{
		best_match = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->value > b->value && cur_a->value < best_match)
			{
				best_match = cur_a->value;
				target_node = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	a_size;
	int	b_size;

	a_size = remake_lstsize(a);
	b_size = remake_lstsize(b);
	while (b)
	{
		b->push_price = b->current_pos;
		if (!(b->above_median))
			b->push_price = b_size - (b->current_pos);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_pos;
		else
			b->push_price += a_size - (b->target_node->current_pos);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*best_match;

	if (!b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match = b;
		}
		b = b->next;
	}
	best_match->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	current_pos(a);
	current_pos(b);
	target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
