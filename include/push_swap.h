/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:22:25 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 15:21:25 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					target_pos;
	int					index;
	int					cost_a;
	int					cost_b;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

typedef struct s_stack_list
{
	t_stack_node		*head;
	t_stack_node		*tail;
	int					length;
}						t_stack_list;

// check functions
char					**check_input(int argc, char **argv);
void					check_characters(char *argv);
void					check_limit(char *argv);
void					check_double(t_stack_list *stack);
void					print_error(void);

// linked list functions
t_stack_list			*create_stack(int argc, char **argv);
void					add_node(t_stack_list *stack, int value);
void					clear_stack(t_stack_list *stack);
int						stack_length(t_stack_list *stack);
void					copy_stack(t_stack_list *src, t_stack_list *dest);

// assign positions (index, current_pos and target_pos)
void					get_positions(t_stack_list *stack_a,
							t_stack_list *stack_b);
void					get_cur_pos(t_stack_list *stack);
int						get_target_pos(t_stack_list *stack, int index_b,
							int max_index, int target);
int						get_lowest_index_pos(t_stack_list *stack);
void					assign_index(t_stack_list *stack);
t_stack_node			*merge_sorted_lists(t_stack_node *a, t_stack_node *b);
void					find_middle_and_split(t_stack_node *source,
							t_stack_node **front_ref, t_stack_node **back_ref);
void					merge_sort(t_stack_node **head_ref);

// operations
void					push(t_stack_list *src, t_stack_list *dest);
void					pb(t_stack_list *stack_a, t_stack_list *stack_b);
void					pa(t_stack_list *stack_a, t_stack_list *stack_b);
void					reverse_rotate(t_stack_list *stack);
void					rra(t_stack_list *stack_a);
void					rrb(t_stack_list *stack_b);
void					rrr(t_stack_list *stack_a, t_stack_list *stack_b);
void					rotate(t_stack_list *stack);
void					ra(t_stack_list *stack_a);
void					rb(t_stack_list *stack_b);
void					rr(t_stack_list *stack_a, t_stack_list *stack_b);
void					swap(t_stack_list *stack);
void					sa(t_stack_list *stack_a);
void					sb(t_stack_list *stack_b);
void					ss(t_stack_list *stack_a, t_stack_list *stack_b);

// sorting algorithm
void					sort_stack(t_stack_list *stack_a,
							t_stack_list *stack_b);
int						is_sorted(t_stack_list *stack);
void					sort_three(t_stack_list *stack);
void					sort_bigger(t_stack_list *stack_a,
							t_stack_list *stack_b);
void					populate_stack_b(t_stack_list *stack_a,
							t_stack_list *stack_b);
void					adjust_stack(t_stack_list *stack_a);
void					do_cheapest_move(t_stack_list *stack_a,
							t_stack_list *stack_b);
void					do_move(t_stack_list *stack_a, t_stack_list *stack_b,
							int cheapest_cost_a, int cheapest_cost_b);

// calculate cost
void					get_cost(t_stack_list *stack_a, t_stack_list *stack_b);
int						get_cheaper_cost(int cost_a, int cost_b);
void					cost_is_positive(t_stack_list *stack_a, \
t_stack_list *stack_b, int *cheapest_a, int *cheapest_b);
void					cost_is_negative(t_stack_list *stack_a, \
t_stack_list *stack_b, int *cheapest_a, int *cheapest_b);
void					cost_a_is_positive(t_stack_list *stack_a, \
t_stack_list *stack_b, int *cheapest_a, int *cheapest_b);
void					cost_b_is_positive(t_stack_list *stack_a, \
t_stack_list *stack_b, int *cheapest_a, int *cheapest_b);

#endif