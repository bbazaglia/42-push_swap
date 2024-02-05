/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:22:16 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 15:24:49 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	check_move(char *str, t_stack_list *stack_a, t_stack_list *stack_b);
void	check_sort(t_stack_list *stack_a, t_stack_list *stack_b);
void	read_moves(t_stack_list *stack_a, t_stack_list *stack_b);
void	sa_bonus(t_stack_list *stack_a);
void	ra_bonus(t_stack_list *stack_a);
void	rb_bonus(t_stack_list *stack_b);
void	rr_bonus(t_stack_list *stack_a, t_stack_list *stack_b);
void	rra_bonus(t_stack_list *stack_a);
void	rrb_bonus(t_stack_list *stack_b);
void	rrr_bonus(t_stack_list *stack_a, t_stack_list *stack_b);
void	pa_bonus(t_stack_list *stack_b, t_stack_list *stack_a);
void	pb_bonus(t_stack_list *stack_a, t_stack_list *stack_b);

#endif