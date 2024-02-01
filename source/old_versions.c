#include "push_swap.h"

// to do: refactor the do_move function
// cost_is_positive(stack_a, stack_b, &cheapest_a, &cheapest_b);
// cost_is_negative(stack_a, stack_b, &cheapest_a, &cheapest_b);
// cost_a_is_positive(stack_a, stack_b, &cheapest_a, &cheapest_b);
// cost_b_is_positive(stack_a, stack_b, &cheapest_a, &cheapest_b);

// void	cost_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
// 		int *cheapest_a, int *cheapest_b)
// {
// 	if (*cheapest_a > 0 && *cheapest_b > 0)
// 	{
// 		while (*cheapest_a > 0 && *cheapest_b > 0)
// 		{
// 			rr(stack_a, stack_b);
// 			(*cheapest_a)--;
// 			(*cheapest_b)--;
// 		}
// 	}
// }

// void	cost_is_negative(t_stack_list *stack_a, t_stack_list *stack_b,
// 		int *cheapest_a, int *cheapest_b)
// {
// 	else if (*cheapest_a < 0 && *cheapest_b < 0)
// 	{
// 		while (*cheapest_a < 0 && *cheapest_b < 0)
// 		{
// 			rrr(stack_a, stack_b);
// 			(*cheapest_a)++;
// 			(*cheapest_b)++;
// 		}
// 	}
// }

// void	cost_a_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
// 		int *cheapest_a, int *cheapest_b)
// {
// 	if (*cheapest_a > 0 && *cheapest_b < 0)
// 	{
// 		while (*cheapest_a > 0)
// 		{
// 			ra(stack_a);
// 			(*cheapest_a)--;
// 		}
// 		while (*cheapest_b < 0)
// 		{
// 			rrb(stack_b);
// 			(*cheapest_b)++;
// 		}
// 	}
// }

// void	cost_b_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
// 		int *cheapest_a, int *cheapest_b)
// {
// 	if (*cheapest_a < 0 && *cheapest_b > 0)
// 	{
// 		while (*cheapest_a < 0)
// 		{
// 			rra(stack_a);
// 			(*cheapest_a)++;
// 		}
// 		while (*cheapest_b > 0)
// 		{
// 			rb(stack_b);
// 			(*cheapest_b)--;
// 		}
// 	}
// }


void	print_stack(t_stack_list *stack)
{
	t_stack_node *current_node;

	current_node = stack->head;
	while (current_node != NULL)
	{
		printf("index = %d\n value = %d\n", current_node->index,
				current_node->value);
		// printf("index is %d\n and value is %d\n", current_node->index, current_node->value);
		current_node = current_node->next;
	}
}

// far too long function
void	before_refactored_do_cheapest_move(t_stack_list *stack_a, t_stack_list *stack_b)
{
	t_stack_node	*cur_b;
	int				cheapest_cost;
	int				cheapest_a;
	int				cheapest_b;
	int 			cur_cost;

	cur_b = stack_b->head;
	cheapest_cost = INT_MAX;
	cur_cost = 0;
	while (cur_b)
	{
		if (cur_b->cost_a > 0 && cur_b->cost_b > 0)
		{
			if (cur_b->cost_a > cur_b->cost_b)
				cur_cost = cur_b->cost_a;
			else 
				cur_cost = cur_b->cost_b;
			if (cur_cost < cheapest_cost)
			{
				cheapest_cost = cur_cost;
				cheapest_a = cur_b->cost_a;
				cheapest_b = cur_b->cost_b;
			}
		}
		if (cur_b->cost_a < 0 && cur_b->cost_b < 0)
		{
			if (cur_b->cost_a < cur_b->cost_b)
				cur_cost = cur_b->cost_a;
			else 
				cur_cost = cur_b->cost_b;
			if (ft_abs(cur_cost) < cheapest_cost)
			{
				cheapest_cost = ft_abs(cur_cost);
				cheapest_a = cur_b->cost_a;
				cheapest_b = cur_b->cost_b;
			}
		}
		else 
		{
			if (ft_abs(cur_b->cost_a) + ft_abs(cur_b->cost_b) < ft_abs(cheapest_cost))
			{
				cheapest_cost = ft_abs(cur_b->cost_a) + ft_abs(cur_b->cost_b);
				cheapest_a = cur_b->cost_a;
				cheapest_b = cur_b->cost_b;
			}
		}
		cur_b = cur_b->next;
	}
	do_move(stack_a, stack_b, cheapest_a, cheapest_b);
}

// this version does not optimize the code if the costs are both negative or both positive
void	old_do_cheapest_move(t_stack_list *stack_a, t_stack_list *stack_b)
{
	t_stack_node	*cur_b;
	int				cheapest_cost;
	int				cheapest_a;
	int				cheapest_b;

	cur_b = stack_b->head;
	cheapest_cost = INT_MAX;
	while (cur_b)
	{
		// find the cheapest cost to move an element from stack_b to stack_a
		if (ft_abs(cur_b->cost_a)
			+ ft_abs(cur_b->cost_b) < ft_abs(cheapest_cost))
		{
			cheapest_cost = ft_abs(cur_b->cost_a) + ft_abs(cur_b->cost_b);
			cheapest_a = cur_b->cost_a;
			cheapest_b = cur_b->cost_b;
		}
		cur_b = cur_b->next;
	}
	do_move(stack_a, stack_b, cheapest_a, cheapest_b);
}

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