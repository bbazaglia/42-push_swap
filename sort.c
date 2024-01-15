#include "push_swap.h"

void	sort_stack(t_stack_list *stack)
{
	is_sorted(stack);
	if (stack_length(stack) <= 3)
		sort_three(stack);
	// else
		// sort_numbers(stack);
}

void	is_sorted(t_stack_list *stack)
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

void	sort_three(t_stack_list *stack)
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
	is_sorted(stack);
}

// void	sort_numbers(t_stack_list *stack)
// {
// }