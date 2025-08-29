/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:16 by mjameau           #+#    #+#             */
/*   Updated: 2024/07/08 12:27:16 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Fonction pour aller a la derniere node de la stack et ajouter la nouvelle,
si y a pas de last bah c elle la last*/
/*ensuite fonction pour trouver la node la plus petite */
/*ensuite fonction pour retourner la node "cheapest"
en gros celle qui coute le moins d'operations*/

#include "push_swap.h"

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = remake_lstlast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack_node	*smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
