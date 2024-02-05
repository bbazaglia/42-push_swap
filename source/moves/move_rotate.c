/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:23:29 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 14:37:10 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_list *stack)
{
	t_stack_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	if (stack->head->next->index == stack->tail->index)
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		stack->head->next = tmp;
		stack->tail = tmp;
		stack->tail->prev = stack->head;
		stack->tail->next = NULL;
	}
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		stack->tail->next = tmp;
		tmp->prev = stack->tail;
		tmp->next = NULL;
		stack->tail = tmp;
	}
}

void	ra(t_stack_list *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_list *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_list *stack_a, t_stack_list *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
