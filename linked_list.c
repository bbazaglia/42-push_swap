#include "push_swap.h"

t_stack_list	*create_stack(int argc, char **argv)
{
	t_stack_list	*stack;
	int				i;
	int				value;

	stack = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (!stack)
		print_error();
	stack->head = NULL;
	stack->tail = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		add_node(stack, value);
		i++;
	}
	return (stack);
}

void	add_node(t_stack_list *stack, int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		print_error();
	new_node->value = value;
	new_node->current_pos = 0; 
    new_node->target_pos = 0; 
    new_node->index = 0; 
    new_node->cost_a = 0; 
    new_node->cost_b = 0;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	if (stack->tail)
		stack->tail->next = new_node;
	stack->tail = new_node;
	if (!stack->head)
		stack->head = new_node;
}

void clear_stack(t_stack_list *stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	while (stack->head)
	{
		tmp = stack->head->next;
		free(stack->head);
		stack->head = tmp;
	}
	free(stack);
}

int stack_length(t_stack_list *stack)
{
	int				length;
	t_stack_node	*tmp;

	length = 0;
	tmp = stack->head;
	while (tmp)
	{
		length++;
		tmp = tmp->next;
	}
	return (length);
}

void	copy_stack(t_stack_list *src, t_stack_list *dest)
{
	t_stack_node	*current_node;

	current_node = src->head;
	while (current_node != NULL)
	{
		add_node(dest, current_node->value);
		current_node = current_node->next;
	}
}