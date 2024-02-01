#include "push_swap.h"

// the first element becomes the last one
void	rotate(t_stack_list *stack)
{
	t_stack_node	*tmp;

	// check if the stack is empty or contains only one node.
	if (stack->head == NULL || stack->head->next == NULL)
		return ;

	// tmp stores the first node
	tmp = stack->head;

	// if the stack contains only two nodes
	if (stack->head->next->index == stack->tail->index)
	{
		// move the second node to the front of the stack
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		stack->head->next = tmp;

		// update the tail pointer of the first node
		stack->tail = tmp;
		stack->tail->prev = stack->head;
		stack->tail->next = NULL;
	}

	// if the stack contains more than two nodes
	else
	{
		// the second node becomes the new first
		stack->head = stack->head->next;
		// break the connection between the first node and the rest of the stack
		stack->head->prev = NULL;
		// the "old first" node becomes the last one
		stack->tail->next = tmp;
		tmp->prev = stack->tail;
		tmp->next = NULL;
		// update the tail pointer
		stack->tail = tmp;
	}
}

void	ra(t_stack_list *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_list *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_list *stack_a, t_stack_list *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}