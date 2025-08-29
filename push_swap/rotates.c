/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:34:41 by mjameau           #+#    #+#             */
/*   Updated: 2024/07/08 11:56:28 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*fonction pour rotate voila pareil */
#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = remake_lstsize(*stack);
	if (!*stack || !stack || len == 1)
		return ;
	last = remake_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack_node **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}
