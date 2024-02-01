#include "push_swap.h"

// this function does not update the pointers correctly
void	old_sort_three(t_stack_list *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (stack_length(stack) == 2)
		sa(stack);
	else if (stack_length(stack) == 3)
	{
		first = stack->head;
		second = first->next;
		third = second->next;
		if (first > second && first > third)
			ra(stack);
		else if (second > first && second > third)
			rra(stack);
		if (first > second)
			sa(stack);
	}
}

// this function can't be used further in the code because it exits the program
void	old_is_sorted(t_stack_list *stack)
{
	int				i;
	t_stack_node	*prev_node;
	t_stack_node	*tmp;
	i = 0;
	prev_node = NULL;
	tmp = stack->head;
	while (tmp)
	{
		if (prev_node && tmp->value < prev_node->value)
			i++;
		prev_node = tmp;
		tmp = tmp->next;
	}
	if (i == 0)
	{
		clear_stack(stack);
		write(1, "The stack is sorted\n", 20);
		exit(0);
	}
}

// this function merges the original list instead of sorting a temporary list that won't be used further in the program
void	old_assign_position(t_stack_list *stack)
{
	t_stack_node	*current;
	int				i;

	current = stack->head;
	i = 1;
	// assign current_pos before sorting
	while (current)
	{
		current->current_pos = i++;
		current = current->next;
	}
	// sort the list using merge sort
	merge_sort(&(stack->head));
	// reset current to the head of the list after sorting
	current = stack->head;
	i = 1;
	// assign target_pos after sorting
	while (current)
	{
		current->target_pos = i++;
		current = current->next;
	}
}

/* it's not necessary to assign the current position before sorting, 
as we will only use the current position only sending the numbers to stack B 
*/
void	old_assign_index(t_stack_list *stack)
{
	t_stack_list	*temp_stack;
	t_stack_node	*current_node;
	int				current_pos;
	int				index;

	// create a temporary stack
	temp_stack = (t_stack_list *)malloc(sizeof(t_stack_list));
	temp_stack->head = NULL;
	temp_stack->tail = NULL;

	// copy the original stack to the temporary stack
	copy_stack(stack, temp_stack);

	// sort the temporary stack using merge sort
	merge_sort(&(temp_stack->head));

	// assign current_pos based on initial position in the original stack
	current_pos = 1;
	current_node = stack->head;
	while (current_node != NULL)
	{
		current_node->current_pos = current_pos++;
		current_node = current_node->next;
	}

	// assign index based on sorted position in the temporary stack
	index = 1;
	current_node = temp_stack->head;
	while (current_node != NULL)
	{
		current_node->index = index++;
		current_node = current_node->next;
	}

	// free the temporary stack
	clear_stack(temp_stack);
}

/* to visualize push function on python tutor:
#include <stdlib.h>

typedef struct s_stack
{
    int                value;
    struct s_stack    *next;
}    t_stack;

static void    push(t_stack **src, t_stack **dest)
{
    t_stack    *tmp;

    if (*src == NULL)
        return ;
        
    tmp = (*src)->next;
    (*src)->next = *dest;
    *dest = *src;
    *src = tmp;
}

int main(void)
{
  t_stack *src;
  t_stack *dest;
  t_stack *temp;
  
  src = NULL;
  
  temp = malloc(sizeof(t_stack));
  temp->value = 10;
  
  src = temp;
  
  temp = malloc(sizeof(t_stack));
  temp->value = 20;
  
  src->next = temp;
  
  src->next->next = NULL;
  
  
  dest = NULL;
  
  temp = malloc(sizeof(t_stack));
  temp->value = 1;
  
  dest = temp;
  
  temp = malloc(sizeof(t_stack));
  temp->value = 2;
  
  dest->next = temp;
  
  dest->next->next = NULL;
  
  
  push(&src, &dest);
  
}
*/