#include "push_swap.h"

void do_cheapest_move(t_stack_list *stack_a, t_stack_list *stack_b)
{
    t_stack_node *current_b;
    int cheapest_cost;
    int cheapest_cost_a;
    int cheapest_cost_b;

    current_b = stack_b->head;
    cheapest_cost = INT_MAX;

    while (current_b)
    {
        // find the cheapest cost to move an element from stack_b to stack_a
        if (ft_abs(current_b->cost_a) + ft_abs(current_b->cost_b) < ft_abs(cheapest_cost))
        {
            cheapest_cost = ft_abs(current_b->cost_a) + ft_abs(current_b->cost_b);
            cheapest_cost_a = current_b->cost_a;
            cheapest_cost_b = current_b->cost_b;
        }
        current_b = current_b->next;
    }
    do_move(stack_a, stack_b, cheapest_cost_a, cheapest_cost_b);
}

void do_move(t_stack_list *stack_a, t_stack_list *stack_b, int cheapest_cost_a, int cheapest_cost_b)
{
    if (cheapest_cost_a > 0 && cheapest_cost_b > 0)
    {
        while (cheapest_cost_a-- > 0 && cheapest_cost_b-- > 0)
            rr(stack_a, stack_b);
    }
    else if (cheapest_cost_a < 0 && cheapest_cost_b < 0)
    {
        while (cheapest_cost_a++ < 0 && cheapest_cost_b++ < 0)
            rrr(stack_a, stack_b);
    }
    else if (cheapest_cost_a >= 0 && cheapest_cost_b <= 0)
    {
        while (cheapest_cost_a-- > 0)
            ra(stack_a);
        while (cheapest_cost_b++ < 0)
            rrb(stack_b);
    }
    else if (cheapest_cost_a <= 0 && cheapest_cost_b >= 0)
    {
        while (cheapest_cost_a++ < 0)
            rra(stack_a);
        while (cheapest_cost_b-- > 0)
            rb(stack_b);
    }
    pa(stack_a, stack_b);
}

