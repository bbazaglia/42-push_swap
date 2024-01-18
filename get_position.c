#include "push_swap.h"

void	get_positions(t_stack_list *stack_a, t_stack_list *stack_b)
{
	t_stack_node	*current_b;
	int target;
	
	current_b = stack_b->head;
	get_cur_pos(stack_a);
	get_cur_pos(stack_b);
	target = 0;
	while (current_b)
	{
		target = get_target_pos(stack_a, current_b->index, INT_MAX, target);
		current_b->target_pos = target;
		current_b = current_b->next;
	}
}

void	get_cur_pos(t_stack_list *stack)
{
	t_stack_node	*current;
	int				i;

	current = stack->head;
	i = 1;
	while (current)
	{
		current->current_pos = i++;
		current = current->next;
	}
}

int	get_target_pos(t_stack_list *stack, int index_b, int max_index, int target)
{
	t_stack_node	*current_a;

	current_a = stack->head;
	while (current_a)
	{
		// find the smallest index in stack_a that is bigger than current_b->index
		if (current_a->index > index_b && current_a->index < INT_MAX)
		{
			max_index = current_a->index;
			target = current_a->current_pos;
		}
		current_a = current_a->next;
	}
	
	// if no target is found, find the smallest index in stack_a
	if (target == 0)
	{
		while (current_a)
		{
			if (current_a->index < max_index)
			{
				max_index = current_a->index;
				target = current_a->current_pos;
			}
			current_a = current_a->next;
		}
		return (target);
	}
	return (target);
}

int get_lowest_index_pos(t_stack_list *stack)
{
	t_stack_node	*current;
	int				lowest_index;
	int				lowest_index_pos;

	current = stack->head;
	lowest_index = INT_MAX;
	lowest_index_pos = 0;
	while (current)
	{
		if (current->index < lowest_index)
		{
			lowest_index = current->index;
			lowest_index_pos = current->current_pos;
		}
		current = current->next;
	}
	return (lowest_index_pos);
}