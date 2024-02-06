/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:25:48 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 14:30:05 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_list	*create_stack(int argc, char **argv)
{
	t_stack_list	*stack;

	stack = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (!stack)
		print_error();
	ft_memset(stack, 0, sizeof(t_stack_list));
	if (argc == 2)
		populate_stack(stack, argv, 0);
	else if (argc > 2)
		populate_stack(stack, argv, 1);
	return (stack);
}

void populate_stack(t_stack_list *stack, char **argv, int start_index)
{
	int i;
	int value;

	i = start_index;
	while (argv[i])
	{
		value = ft_atol(argv[i]);
		add_node(stack, value);
		i++;
	}
}

void	add_node(t_stack_list *stack, int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		print_error();
	ft_memset(new_node, 0, sizeof(t_stack_node));
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	if (!stack->head)
		stack->head = new_node;
	if (stack->tail)
		stack->tail->next = new_node;
	stack->tail = new_node;
	stack->length++;
}

void clear_stack(t_stack_list *stack)
{
    t_stack_node *cur;

    if (stack)
	{
		while (stack->head)
		{
			cur = stack->head->next;
			free(stack->head);
			stack->head = cur;
		}
		free(stack);
	}
}

void	copy_stack(t_stack_list *src, t_stack_list *dest)
{
	t_stack_node	*cur;

	cur = src->head;
	while (cur != NULL)
	{
		add_node(dest, cur->value);
		cur = cur->next;
	}
}