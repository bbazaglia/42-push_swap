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

/*
Unfortunatelly, your suggestion does not work. 
My code will push some elements from stack_a to stack_b, but the stack_b is empty.
I have to make my code works even when the stack_b is empty.
Take a look at my code and fix it:

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					target_pos;
	int					index;
	int					cost_a;
	int					cost_b;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

typedef struct s_stack_list
{
	t_stack_node		*head;
	t_stack_node		*tail;
}						t_stack_list;

int	main(int argc, char **argv)
{
	t_stack_list	*stack_a;
	t_stack_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	check_input(argc, argv);
	stack_a = create_stack(argc, argv);
	check_double(stack_a);
	assign_index(stack_a);
	sort_stack(stack_a, stack_b);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}

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


*/