#include "push_swap.h"

// void	swap(t_stack_list *stack)
// {
// 	t_stack_node	*temp;

// 	if (stack->head == NULL || stack->head->next == NULL)
// 		return ;
// 	temp = stack->head;
// 	stack->head = stack->head->next;
// 	temp->next = stack->head->next;
// 	stack->head->next = temp;
// }

void	swap(t_stack_list *stack)
{
	int tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;

	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
	tmp = stack->head->index;
	stack->head->index = stack->head->next->index;
	stack->head->next->index = tmp;
}

// void    swap(t_stack_list *stack)
// {
//     t_stack_node    *temp;

//     if (stack->head == NULL || stack->head->next == NULL)
//         return ;
//     temp = stack->head;
//     temp->prev = stack->head->next;
//     stack->head = stack->head->next;
//     temp->next = stack->head->next;
//     stack->head->prev = NULL;
//     stack->head->next = temp;
//     stack->head->next->next->prev = stack->head->next;
// }

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
