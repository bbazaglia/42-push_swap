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

// instead of using the value, it would be possible to use the index
void	sort_three(t_stack_list *stack)
{
	if (stack->head->value > stack->head->next->value
		&& stack->head->value > stack->head->next->next->value)
		ra(stack);
	else if (stack->head->next->value > stack->head->value
			&& stack->head->next->value > stack->head->next->next->value)
		rra(stack);
	if (stack->head->value > stack->head->next->value)
		sa(stack);
}

void	sort_bigger(t_stack_list *stack_a, t_stack_list *stack_b, int length_a)
{
	// pb all elements from stack A, except three.
	while (length_a > 3)
	{
		if (stack_a->head->index < length_a / 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}

	// sort the 3 numbers left in stack A.
	sort_three(stack_a);

	while (stack_length(stack_b) > 0)
	{
		// Find the current position of every element in stack A and B.

		// Calculate the target position in stack A where each element in stack B should be.

		// Calculate the number of actions (the cost) to put each element in stack B at its target position in stack A and choose the element that’s cheapest to move.

		// Execute the sequence of actions needed to move the element from stack B to stack A.

		// If stack A is not sorted, chose between ra and rra to rotate it into ascending order.
	}
}