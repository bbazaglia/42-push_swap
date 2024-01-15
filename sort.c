#include "push_swap.h"

void	is_sorted(t_stack_list *stack)
{
	int		i;
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
		print_error();
	}
}

