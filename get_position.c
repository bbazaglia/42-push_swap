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

	// t_stack_node *temp10 = stack_a->head;
	// printf("\nstack A after running get_positions:\n");
	// while (temp10)
	// {
	// 	printf("index: %d and value: %d\n", temp10->index, temp10->value);
	// 	temp10 = temp10->next;
	// }  

	// t_stack_node *temp11 = stack_b->head;
	// printf("\nstack B after running get_positions:\n");
	// while (temp11)
	// {
	// 	printf("index: %d and value: %d\n", temp11->index, temp11->value);
	// 	temp11 = temp11->next;
	// }  
}

void	get_cur_pos(t_stack_list *stack)
{
	t_stack_node	*current;
	int				i;

	current = stack->head;
	i = 0;
	while (current)
	{
		current->current_pos = i++;
		current = current->next;
	}
}

int	get_target_pos(t_stack_list *stack, int index_b, int target_index, int target)
{
	t_stack_node	*current_a;

	current_a = stack->head;
	while (current_a)
	{
		// find the smallest index in stack_a that is bigger than current_b->index
		if (current_a->index > index_b && current_a->index < target_index)
		{
			target_index = current_a->index;
			target = current_a->current_pos;
		}
		current_a = current_a->next;
	}
	
	// if no target is found, find the smallest index in stack_a
	if (target == 0)
	{
		while (current_a)
		{
			if (current_a->index < target_index)
			{
				target_index = current_a->index;
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
	get_cur_pos(stack);
	lowest_index_pos = current->current_pos;
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