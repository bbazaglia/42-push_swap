#include "push_swap.h"

// the last element becomes the first one
void	reverse_rotate(t_stack_list *stack)
{
	t_stack_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;

	// tmp stores the last node
	tmp = stack->tail;

	// update the tail pointer to the second last node
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	
	// add the last node to the front of the stack
	tmp->next = stack->head;
	tmp->prev = NULL;

	// update the head pointer to the last node
	stack->head->prev = tmp;
	stack->head = tmp;
}

void	rra(t_stack_list *stack_a)
{
	reverse_rotate(stack_a);
	// write(1, "rra\n", 4);
}

void	rrb(t_stack_list *stack_b)
{
	reverse_rotate(stack_b);
	// write(1, "rrb\n", 4);
}

void	rrr(t_stack_list *stack_a, t_stack_list *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	// write(1, "rrr\n", 4);
}