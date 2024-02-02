#include "push_swap.h"

void	do_cheapest_move(t_stack_list *stack_a, t_stack_list *stack_b)
{
	t_stack_node	*cur_b;
	int				cheapest_cost;
	int				cheapest_a;
	int				cheapest_b;
	int				cur_cost;

	cur_b = stack_b->head;
	cheapest_cost = INT_MAX;
	cur_cost = 0;
	while (cur_b)
	{
		cur_cost = get_cheaper_cost(cur_b->cost_a, cur_b->cost_b);
		if (ft_abs(cur_cost) < cheapest_cost)
		{
			cheapest_cost = ft_abs(cur_cost);
			cheapest_a = cur_b->cost_a;
			cheapest_b = cur_b->cost_b;
		}
		cur_b = cur_b->next;
	}
	do_move(stack_a, stack_b, cheapest_a, cheapest_b);
}

void	cost_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a > 0 && *cheapest_b > 0)
	{
		while (*cheapest_a > 0 && *cheapest_b > 0)
		{
			rr(stack_a, stack_b);
			(*cheapest_a)--;
			(*cheapest_b)--;
		}
	}
}

void	cost_is_negative(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a < 0 && *cheapest_b < 0)
	{
		while (*cheapest_a < 0 && *cheapest_b < 0)
		{
			rrr(stack_a, stack_b);
			(*cheapest_a)++;
			(*cheapest_b)++;
		}
	}
}

void	cost_a_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a >= 0 && *cheapest_b <= 0)
	{
		while (*cheapest_a > 0)
		{
			ra(stack_a);
			(*cheapest_a)--;
		}
		while (*cheapest_b < 0)
		{
			rrb(stack_b);
			(*cheapest_b)++;
		}
	}
}

void	cost_b_is_positive(t_stack_list *stack_a, t_stack_list *stack_b,
		int *cheapest_a, int *cheapest_b)
{
	if (*cheapest_a <= 0 && *cheapest_b >= 0)
	{
		while (*cheapest_a < 0)
		{
			rra(stack_a);
			(*cheapest_a)++;
		}
		while (*cheapest_b > 0)
		{
			rb(stack_b);
			(*cheapest_b)--;
		}
	}
}

void	do_move(t_stack_list *stack_a, t_stack_list *stack_b, int cheapest_a,
		int cheapest_b)
{
	cost_is_positive(stack_a, stack_b, &cheapest_a, &cheapest_b);
	cost_is_negative(stack_a, stack_b, &cheapest_a, &cheapest_b);
	cost_a_is_positive(stack_a, stack_b, &cheapest_a, &cheapest_b);
	cost_b_is_positive(stack_a, stack_b, &cheapest_a, &cheapest_b);
	pa(stack_b, stack_a);
}
