#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>


typedef struct s_stack
{
	int				value;
	int				current_pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;


// handle errors

// operations 

// stack length 

// last stack 

// min and max stacks