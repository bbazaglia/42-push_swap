#include "push_swap.h"

// push a new element onto the front of the stack
void push(t_stack_list *src_stack, t_stack_list *dest_stack)
{
	t_stack_node *tmp;

	// if the source stack is empty, there is nothing to push
	if (src_stack->head == NULL)
		return;

	// create a pointer to the next element in the source stack
	tmp = src_stack->head->next;

	if (tmp)
		// if the source stack had more than one element, the new head is the next element
		tmp->prev = NULL;
	else
		// if the source stack had only one element, the stack is now empty
		src_stack->tail = NULL; 

	// update the pointers of the destination stack
	src_stack->head->next = dest_stack->head;
	if (dest_stack->head)
		dest_stack->head->prev = src_stack->head;

	// update the pointers of the source stack
	dest_stack->head = src_stack->head;
	src_stack->head = tmp;
}

void pa(t_stack_list *stack_a, t_stack_list *stack_b)
{
    push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void pb(t_stack_list *stack_a, t_stack_list *stack_b)
{
    push(stack_a, stack_b);
	write(1, "pb\n", 3);
}