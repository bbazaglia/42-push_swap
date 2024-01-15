#include "push_swap.h"

void	sort_stack(t_stack_list *stack)
{
	int	len;

	is_sorted(stack);
	len = stack_length(stack);
	if (len == 2)
		sa(stack);
	else if (stack_length(stack) == 3)
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
	if (stack->head->value > stack->head->next->value
		&& stack->head->value > stack->head->next->next->value)
		ra(stack);
	else if (stack->head->next->value > stack->head->value
			&& stack->head->next->value > stack->head->next->next->value)
		rra(stack);
	if (stack->head->value > stack->head->next->value)
		sa(stack);
}

/* this function does not update the pointers correctly
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
}
*/

// void	sort_numbers(t_stack_list *stack)
// {
// }