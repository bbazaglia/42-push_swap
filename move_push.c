#include "push_swap.h"

void pb (t_stack_list *stack_a, t_stack_list *stack_b)
{
	int		value;

	if (!stack_a->head)
		return ;
	value = pop_node(stack_a);
	push_node(stack_b, value);
	write(1, "pb\n", 3);
}

void pa (t_stack_list *stack_a, t_stack_list *stack_b)
{
	int		value;

	if (!stack_b->head)
		return ;
	value = pop_node(stack_b);
	push_node(stack_a, value);
	write(1, "pa\n", 3);
}

// push a new element onto the front of the stack
void push_node(t_stack_list *stack, int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		print_error();
	new_node->value = value;
	new_node->next = stack->head;
	new_node->prev = NULL;
	if (stack->head)
		stack->head->prev = new_node;
	else if (!stack->tail)
		stack->tail = new_node;
	stack->head = new_node;
}

// remove the first element from the stack and return its value
int	pop_node(t_stack_list *stack)
{
	int				popped_value;
	t_stack_node	*popped_node;

	if (!stack->head)
		print_error();
	popped_value = stack->head->value;
	popped_node = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	free(popped_node);
	popped_node = NULL;
	return (popped_value);
}