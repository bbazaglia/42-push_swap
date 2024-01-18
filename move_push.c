#include "push_swap.h"

// push a new element onto the front of the stack
void push(t_stack_list *stack, t_stack_node *new_node)
{
	new_node->next = stack->head;
	new_node->prev = NULL;
	if (stack->head)
		stack->head->prev = new_node;
	else
		stack->tail = new_node; 
	stack->head = new_node;
}

// remove the first element from the stack and return its value
t_stack_node *pop(t_stack_list *stack)
{
	t_stack_node *popped_node;

	if (!stack->head)
		print_error(); 
	popped_node = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	return popped_node;
}

void pa(t_stack_list *stack_a, t_stack_list *stack_b)
{
    if (stack_b->head) 
    {
        t_stack_node *popped_node = pop(stack_b);
        push(stack_a, popped_node);
    }
    else
        print_error();
}

void pb(t_stack_list *stack_a, t_stack_list *stack_b)
{
    if (stack_a->head) 
    {
        t_stack_node *popped_node = pop(stack_a);
        push(stack_b, popped_node);
    }
    else

        print_error();
}
