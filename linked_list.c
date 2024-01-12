#include "push_swap.h"

t_stack	*initialize_stack(int argc, char **argv)
{
	t_stack	*head;
	t_stack	*tail;
	int		i;
	int		value;
	t_stack	*new_node;

	head = NULL;
	tail = NULL;
	i = 1;
	while (i < argc)
	{
		value = atol(argv[i]);
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			print_error();
		new_node->value = value;
		new_node->next = NULL;
		new_node->prev = tail;
		if (tail)
			tail->next = new_node;
		tail = new_node;
		if (!head)
			head = new_node;
		i++;
	}
	return (head);
}

void clear_stack(t_stack *stack)
{
	t_stack *tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

int stack_size(t_stack *stack)
{
	int i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack *stack_tail(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}