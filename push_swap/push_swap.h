/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:09:10 by mjameau           #+#    #+#             */
/*   Updated: 2024/07/08 12:32:03 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;

void					create_stack(t_stack_node **a, char **argv,
							bool flag_argc_2);
void					append_node(t_stack_node **stack, int n);
void					error_free(t_stack_node **a, char **argv,
							bool flag_argc_2);
void					free_stack(t_stack_node **stack);
void					free_matrix(char **argv);
int						error_syntax(char *str_nb);
int						error_repetition(t_stack_node *a, int nbr);
void					end_rota(t_stack_node **stack, t_stack_node *top,
							char stack_name);
void					push_swap(t_stack_node **a, t_stack_node **b);
void					rra(t_stack_node **a, bool checker);
void					rrb(t_stack_node **b, bool checker);
void					rrr(t_stack_node **a, t_stack_node **b, bool checker);
void					ra(t_stack_node **a, bool checker);
void					rb(t_stack_node **b, bool checker);
void					rr(t_stack_node **a, t_stack_node **b, bool checker);
bool					sort_stack(t_stack_node *stack);
void					three_sort(t_stack_node **a);
void					five_sort(t_stack_node **a, t_stack_node **b);
t_stack_node			*smallest(t_stack_node *stack);
t_stack_node			*cheapest(t_stack_node *stack);
void					sa(t_stack_node **a, bool checker);
void					sb(t_stack_node **b, bool checker);
void					ss(t_stack_node **a, t_stack_node **b, bool checker);
void					current_pos(t_stack_node *stack);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *b);
void					init_nodes(t_stack_node *a, t_stack_node *b);
void					pa(t_stack_node **a, t_stack_node **b, bool checker);
void					pb(t_stack_node **a, t_stack_node **b, bool checker);
t_stack_node			*remake_lstlast(t_stack_node *lst);
int						remake_lstsize(t_stack_node *lst);
char					**ft_split_remake(char *str, char separator);

#endif
