/* this function does not update the pointers correctly
void	sort_three(t_stack_list *stack)
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
*/
