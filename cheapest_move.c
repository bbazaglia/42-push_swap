#include "push_swap.h"

void	do_cheapest_move(t_stack_list *stack_a, t_stack_list *stack_b)
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

void	do_move(t_stack_list *stack_a, t_stack_list *stack_b, int cheapest_a,
		int cheapest_b)
{
	if (cheapest_a > 0 && cheapest_b > 0)
	{
		while (cheapest_a > 0 && cheapest_b > 0)
		{
			rr(stack_a, stack_b);
			cheapest_a--;
			cheapest_b--;
		}
	}
	else if (cheapest_a < 0 && cheapest_b < 0)
	{
		while (cheapest_a < 0 && cheapest_b < 0)
		{
			rrr(stack_a, stack_b);
			cheapest_a++;
			cheapest_b++;
		}
	}
	if (cheapest_a >= 0 && cheapest_b <= 0)
	{
		while (cheapest_a > 0)
		{
			ra(stack_a);
			cheapest_a--;
		}
		while (cheapest_b < 0)
		{
			rrb(stack_b);
			cheapest_b++;
		}
	}
	else if (cheapest_a <= 0 && cheapest_b >= 0)
	{
		while (cheapest_a < 0)
		{
			rra(stack_a);
			cheapest_a++;
		}
		while (cheapest_b > 0)
		{
			rb(stack_b);
			cheapest_b--;
		}
	}
	pa(stack_a, stack_b);
}
