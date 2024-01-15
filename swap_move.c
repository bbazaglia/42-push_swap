#include "push_swap.h"

void	swap(t_stack_list *stack)
{
	t_stack_node	*temp;

	if (stack->head == NULL || stack->head->next == NULL)
		print_error();
	temp = stack->head;
	stack->head = stack->head->next;
	temp->next = stack->head->next;
	stack->head->next = temp;
}

void	sa(t_stack_list *stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_list *stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_list *stack_a, t_stack_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
