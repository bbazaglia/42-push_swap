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
		if (current->index > current->next->index)
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
		// calculate the current position of each element in stack A and stack B and the target position of each element in stack B
		get_positions(stack_a, stack_b);

		// calculate the number of actions (the cost) to put each element in stack B at its target position in stack A
		get_cost(stack_a, stack_b);

		// move the element from stack B to stack A that has the lowest cost
		do_cheapest_move(stack_a, stack_b);	
	}
	if (is_sorted(stack_a) == 0)
		adjust_stack_a(stack_a);
}

void	adjust_stack_a(t_stack_list *stack_a)
{
	int	lowest_pos;
	int len;

	len = stack_length(stack_a);
	lowest_pos = get_lowest_index_pos(stack_a);
	if (lowest_pos > len / 2)
	{
		while (lowest_pos++ < len)
			rra(stack_a);
	}
	else
	{
		while (lowest_pos-- > 0)
			ra(stack_a);
	}
}