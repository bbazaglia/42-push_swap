/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:23:53 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/19 10:56:48 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack_list *stack, int argc, char **argv)
{
	int				len;
	t_stack_node	*highest;

	len = stack->length;
	highest = NULL;
	while (len > 0)
	{
		find_highest_unassigned(stack, &highest, argc, argv);
		if (highest)
			highest->index = len;
		len--;
	}
}

void	find_highest_unassigned(t_stack_list *stack, t_stack_node **highest,
		int argc, char **argv)
{
	t_stack_node	*cur;
	int				value;

	cur = stack->head;
	value = INT_MIN;
	while (cur)
	{
		if (cur->value == INT_MIN && cur->index == 0)
			cur->index = 1;
		if (cur->value > value && cur->index == 0)
		{
			check_duplicate(stack, cur, argc, argv);
			value = cur->value;
			*highest = cur;
			cur = stack->head;
		}
		else
			cur = cur->next;
	}
}
