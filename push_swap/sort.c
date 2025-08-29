/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:12:12 by mjameau           #+#    #+#             */
/*   Updated: 2024/07/08 11:57:10 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*fonctions basiques pour voir si la stack est triee,
	trouver la plus grande node, et trier par 3 ou 5*/

#include "push_swap.h"

bool	sort_stack(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack_node	*biggest(t_stack_node *stack)
{
	int				biggest;
	t_stack_node	*biggest_node;

	if (!stack)
		return (NULL);
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->value > biggest)
		{
			biggest = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	three_sort(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = biggest(*a);
	if (*a == biggest_node)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	five_sort(t_stack_node **a, t_stack_node **b)
{
	while (remake_lstsize(*a) > 3)
	{
		init_nodes(*a, *b);
		end_rota(a, smallest(*a), 'a');
		pb(b, a, false);
	}
}
