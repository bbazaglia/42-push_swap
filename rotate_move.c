#include "push_swap.h"

void	rotate(t_stack **head)
{
	t_stack *tmp;
	t_stack *tail;

	if (*head == NULL || (*head)->next == NULL)
		print_error();

	tail = stack_tail(*head);
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tail->next = tmp;
	tmp->prev = tail;
	tmp->next = NULL;
}

void ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}