#include "push_swap.h"

void	assign_index(t_stack_list *stack)
{
	t_stack_list	*temp_stack;
	t_stack_node	*current_node;
	int				index;

	// create a temporary stack
	temp_stack = (t_stack_list *)malloc(sizeof(t_stack_list));
	temp_stack->head = NULL;
	temp_stack->tail = NULL;

	// copy the original stack to the temporary stack
	copy_stack(stack, temp_stack);

	// sort the temporary stack using merge sort
	merge_sort(&(temp_stack->head));

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

t_stack_node	*merge_sorted_lists(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*result;

	result = NULL;

	// base cases: if the one list is empty, return the other list
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	// compare values and merge the lists in ascending order
	if (a->value < b->value)
	{
		result = a;
		result->next = merge_sorted_lists(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_sorted_lists(a, b->next);
	}

	// return the merged result
	return (result);
}

void	find_middle_and_split(t_stack_node *source, t_stack_node **front_ref, t_stack_node **back_ref)
{
	t_stack_node	*fast;
	t_stack_node	*slow;

	slow = source;
	fast = source->next;

	// when fast reaches the end, slow will be at the middle (or middle-left node, in case the list has an even number of nodes)
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	// split the list into two halves
	*front_ref = source;
	*back_ref = slow->next;

	// break the link between the two halves
	slow->next = NULL;
}

void	merge_sort(t_stack_node **head_ref)
{
	// create a local pointer to the head of the list
	t_stack_node *head = *head_ref;

	// create pointers that will eventually store the two halves of the list
	t_stack_node *a;
	t_stack_node *b;

	if ((head == NULL) || (head->next == NULL))
		return ;

	// split the list into two halves
	find_middle_and_split(head, &a, &b);

	// recursively sort the sublists
	merge_sort(&a);
	merge_sort(&b);

	// merge the sorted sublists
	*head_ref = merge_sorted_lists(a, b);
}