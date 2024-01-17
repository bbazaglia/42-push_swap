#include "push_swap.h"

void	sort_stack(t_stack_list *stack_a, t_stack_list *stack_b)
{
	int	len;

	len = stack_length(stack_a);
	if (is_sorted(stack_a) == 1)
	{
		clear_stack(stack_a);
		clear_stack(stack_b);
		write(1, "The stack is already sorted\n", 28);
		exit(0);
	}
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else
		sort_bigger(stack_a, stack_b, len);
}

int	is_sorted(t_stack_list *stack)
{
	t_stack_node	*current;

	current = stack->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_stack_list *stack)
{
	if (stack->head->index > stack->head->next->index
		&& stack->head->index > stack->head->next->next->index)
		ra(stack);
	else if (stack->head->next->index > stack->head->index
			&& stack->head->next->index > stack->head->next->next->index)
		rra(stack);
	if (stack->head->index > stack->head->next->index)
		sa(stack);
}

void	sort_bigger(t_stack_list *stack_a, t_stack_list *stack_b, int length_a)
{
	// push all elements from stack A, except 3
	while (length_a > 3)
	{
		// "pre sort" by pushing the smallest indexes to stack B and rotating the biggest indexes to the bottom of stack A
		if (stack_a->head->index <= length_a / 2) 
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}

	// sort the 3 numbers left in stack A
	sort_three(stack_a);

	while (stack_length(stack_b) > 0)
	{
		/* find the current position of every element in stack A and B, 
		then calculate the target position in stack A where each element in stack B should be */
		get_positions(stack_a, stack_b);

		// Calculate the number of actions (the cost) to put each element in stack B at its target position in stack A and choose the element that’s cheapest to move

		// Execute the sequence of actions needed to move the element from stack B to stack A
	
	}
	if (is_sorted(stack_a) == 0)
		// If stack A is not sorted, chose between ra and rra to rotate it into ascending order
}