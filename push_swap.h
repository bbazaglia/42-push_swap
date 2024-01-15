#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// everytime is perfomed an operation that modifies the list, update the head or tail pointer as necessary
typedef struct s_stack_list
{
	t_stack_node		*head;
	t_stack_node		*tail;
}						t_stack_list;

// handle errors

// operations

// stack length

// last stack

// min and max stacks
