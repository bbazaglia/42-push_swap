#include "push_swap.h"

// this function does not update the pointers correctly
void	old_sort_three(t_stack_list *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (stack_length(stack) == 2)
		sa(stack);
	else if (stack_length(stack) == 3)
	{
		first = stack->head;
		second = first->next;
		third = second->next;
		if (first > second && first > third)
			ra(stack);
		else if (second > first && second > third)
			rra(stack);
		if (first > second)
			sa(stack);
	}
}

// this function can't be used further in the code because it exits the program
void	old_is_sorted(t_stack_list *stack)
{
	int				i;
	t_stack_node	*prev_node;
	t_stack_node	*tmp;
	i = 0;
	prev_node = NULL;
	tmp = stack->head;
	while (tmp)
	{
		if (prev_node && tmp->value < prev_node->value)
			i++;
		prev_node = tmp;
		tmp = tmp->next;
	}
	if (i == 0)
	{
		clear_stack(stack);
		write(1, "The stack is sorted\n", 20);
		exit(0);
	}
}

// this function merges the original list instead of sorting a temporary list that won't be used further in the program
void	old_assign_position(t_stack_list *stack)
{
	t_stack_node	*current;
	int				i;

	current = stack->head;
	i = 1;
	// assign current_pos before sorting
	while (current)
	{
		current->current_pos = i++;
		current = current->next;
	}
	// sort the list using merge sort
	merge_sort(&(stack->head));
	// reset current to the head of the list after sorting
	current = stack->head;
	i = 1;
	// assign target_pos after sorting
	while (current)
	{
		current->target_pos = i++;
		current = current->next;
	}
}