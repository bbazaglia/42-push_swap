#include "push_swap.h"

void	is_sorted(t_stack *stack)
{
	int		i;
	t_stack	*prev_node;

	i = 0;
	prev_node = NULL;
	while (stack)
	{
		if (prev_node && stack->value < prev_node->value)
			i++;
		prev_node = stack;
		stack = stack->next;
	}
	if (i == 0)
	{
		clear_stack(stack);
		print_error();
	}
}
