/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:24:41 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 14:34:05 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack_list *stack_a, t_stack_list *stack_b)
{
	t_stack_node	*cur_b;

	cur_b = stack_b->head;
	while (cur_b)
	{
		cur_b->cost_b = cur_b->current_pos;
		if (cur_b->current_pos > stack_b->length / 2)
			cur_b->cost_b = (stack_b->length - cur_b->current_pos) * -1;
		cur_b->cost_a = cur_b->target_pos;
		if (cur_b->target_pos > stack_a->length / 2)
			cur_b->cost_a = (stack_a->length - cur_b->target_pos) * -1;
		cur_b = cur_b->next;
	}
}

void	cost_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a > 0 && *cheapest_b > 0)
	{
		while (*cheapest_a > 0 && *cheapest_b > 0)
		{
			rr(stack_a, stack_b);
			(*cheapest_a)--;
			(*cheapest_b)--;
		}
	}
}

void	cost_is_negative(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a < 0 && *cheapest_b < 0)
	{
		while (*cheapest_a < 0 && *cheapest_b < 0)
		{
			rrr(stack_a, stack_b);
			(*cheapest_a)++;
			(*cheapest_b)++;
		}
	}
}

void	cost_a_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a >= 0 && *cheapest_b <= 0)
	{
		while (*cheapest_a > 0)
		{
			ra(stack_a);
			(*cheapest_a)--;
		}
		while (*cheapest_b < 0)
		{
			rrb(stack_b);
			(*cheapest_b)++;
		}
	}
}

void	cost_b_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a <= 0 && *cheapest_b >= 0)
	{
		while (*cheapest_a < 0)
		{
			rra(stack_a);
			(*cheapest_a)++;
		}
		while (*cheapest_b > 0)
		{
			rb(stack_b);
			(*cheapest_b)--;
		}
	}
}
