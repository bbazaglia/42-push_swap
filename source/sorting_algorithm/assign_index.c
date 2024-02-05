/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:23:53 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 14:35:49 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack_list *stack)
{
	t_stack_list	*temp_stack;
	t_stack_node	*current_temp_node;
	t_stack_node	*current_stack_node;
	int				index;

	temp_stack = (t_stack_list *)malloc(sizeof(t_stack_list));
	temp_stack->head = NULL;
	temp_stack->tail = NULL;
	copy_stack(stack, temp_stack);
	merge_sort(&(temp_stack->head));
	index = 1;
	current_temp_node = temp_stack->head;
	while (current_temp_node)
	{
		current_stack_node = stack->head;
		while (current_stack_node)
		{
			if (current_stack_node->value == current_temp_node->value)
				current_stack_node->index = index;
			current_stack_node = current_stack_node->next;
		}
		current_temp_node = current_temp_node->next;
		index++;
	}
	clear_stack(temp_stack);
}

t_stack_node	*merge_sorted_lists(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->value < b->value)
	{
		result = a;
		result->next = merge_sorted_lists(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_sorted_lists(a, b->next);
	}
	return (result);
}

void	find_middle_and_split(t_stack_node *source, t_stack_node **front_ref,
		t_stack_node **back_ref)
{
	t_stack_node	*fast;
	t_stack_node	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}

void	merge_sort(t_stack_node **head_ref)
{
	t_stack_node	*head;
	t_stack_node	*a;
	t_stack_node	*b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	find_middle_and_split(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*head_ref = merge_sorted_lists(a, b);
}
