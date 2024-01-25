#include "push_swap.h"

void	sort_stack(t_stack_list *stack_a, t_stack_list *stack_b)
{
	int	len;

	len = stack_length(stack_a);
	if (is_sorted(stack_a) == 1)
	{
		clear_stack(stack_a);
		clear_stack(stack_b);
		write(1, "The stack is already sorted\n", 28);
		exit(0);
	}
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else
		sort_bigger(stack_a, stack_b, len);
}

int	is_sorted(t_stack_list *stack)
{
	t_stack_node	*current;

	current = stack->head;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_stack_list *stack)
{
	if (stack->head->index > stack->head->next->index
		&& stack->head->index > stack->head->next->next->index)
		ra(stack);
	else if (stack->head->next->index > stack->head->index
			&& stack->head->next->index > stack->head->next->next->index)
		rra(stack);
	if (stack->head->index > stack->head->next->index)
		sa(stack);
}

void	sort_bigger(t_stack_list *stack_a, t_stack_list *stack_b, int length_a)
{
	// t_stack_node *temp10 = stack_a->head;
	// printf("\nstack A:\n");
	// while (temp10)
	// {
	// 	printf("index: %d and value: %d\n", temp10->index, temp10->value);
	// 	temp10 = temp10->next;
	// }  

	populate_stack_b(stack_a, stack_b, length_a);
	
	// t_stack_node *temp2 = stack_a->head;
	// printf("\nstack A after all elements but 3 are pushed to stack B:\n");
	// while (temp2)
	// {
	// 	printf("index: %d and value: %d\n", temp2->index, temp2->value);
	// 	temp2 = temp2->next;
	// }



    sort_three(stack_a);

	t_stack_node *temp3 = stack_a->head;
	printf("\nstack A after sorting the 3 remaining elements in A:\n");
	while (temp3)
	{
		printf("index: %d and value: %d\n", temp3->index, temp3->value);
		temp3 = temp3->next;
	}

	t_stack_node *temp5 = stack_b->head;
	printf("\nstack B after all elements but 3 are pushed from stack A:\n");
	while (temp5)
	{
		printf("index: %d and value: %d\n", temp5->index, temp5->value);
		temp5 = temp5->next;
	}

    while (stack_length(stack_b))
    {
        get_positions(stack_a, stack_b);
        get_cost(stack_a, stack_b);
        do_cheapest_move(stack_a, stack_b);	

		// t_stack_node *temp10 = stack_a->head;
		// printf("\nstack A after cheapest move is done:\n");
		// while (temp10)
		// {
		// 	printf("index: %d and value: %d\n", temp10->index, temp10->value);
		// 	temp10 = temp10->next;
		// }  

		// t_stack_node *temp11 = stack_b->head;
		// printf("\nstack B:\n");
		// while (temp11)
		// {
		// 	printf("index: %d and value: %d\n", temp11->index, temp11->value);
		// 	temp11 = temp11->next;
		// }  
		
    }

	// t_stack_node *temp = stack_a->head;
	// printf("\nstack A after all elements are back to stack A:\n ");
	// while (temp)
	// {
	// 	printf("index: %d and value: %d\n", temp->index, temp->value);
	// 	temp = temp->next;
	// }

	// printf("\nBefore calling 'is_sorted'\n");
	
    if (!is_sorted(stack_a))
        adjust_stack_a(stack_a);
}

void populate_stack_b(t_stack_list *stack_a, t_stack_list *stack_b, int length_a)
{
    int pushed = 0;
    int i = 0;

    while (length_a > 6 && i < length_a && pushed < length_a / 2)
    {

		// t_stack_node *temp10 = stack_a->head;
		// printf("\nstack A:\n");
		// while (temp10)
		// {
		// 	printf("index: %d and value: %d\n", temp10->index, temp10->value);
		// 	temp10 = temp10->next;
		// }  

        if (stack_a->head->index <= length_a / 2)
        {
            pb(stack_a, stack_b);
			// t_stack_node *temp11 = stack_b->head;
			// printf("\nstack B:\n");
			// while (temp11)
			// {
			// 	printf("index: %d and value: %d\n", temp11->index, temp11->value);
			// 	temp11 = temp11->next;
			// }  

			if (!stack_b->tail)
				stack_b->tail = stack_b->head;
            pushed++;
        }
        else
            ra(stack_a);
        i++;
    }
    while (length_a - pushed > 3)
    {
        pb(stack_a, stack_b);
		if (!stack_b->tail)
				stack_b->tail = stack_b->head;
        pushed++;
    }
}

void	adjust_stack_a(t_stack_list *stack_a)
{
	int	lowest_pos;
	int len;
	t_stack_node *temp;
	temp = stack_a->head;

	len = stack_length(stack_a);
	lowest_pos = get_lowest_index_pos(stack_a);
	if (lowest_pos > len / 2)
	{
		while (lowest_pos++ < len)
			rra(stack_a);
	}
	else
	{
		while (lowest_pos-- > 0)
		{
			printf("lowest pos: %d\n", lowest_pos);
			ra(stack_a);
		}
	}
}