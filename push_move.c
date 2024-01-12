#include "push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int	first_value;

	first_value = pop(stack_a);
	push(stack_b, first_value);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	first_value;

	first_value = pop(stack_b);
	push(stack_a, first_value);
}

// push a new element onto the front of the stack
void	push(t_stack **head, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		print_error();
	new_node->value = value;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;
}

// remove the first element from the stack and return its value
int	pop(t_stack **head)
{
	int		popped_value;
	t_stack	*popped_node;

	if (!*head)
		print_error();
	popped_value = (*head)->value;
	popped_node = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	else
		*head = NULL;
	free(popped_node);
	popped_node = NULL;
	return (popped_value);
}
