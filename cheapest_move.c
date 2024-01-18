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
        if (abs_value(current_b->cost_a) + abs_value(current_b->cost_b) < abs_value(cheapest_cost))
        {
            cheapest_cost = abs_value(current_b->cost_a) + abs_value(current_b->cost_b);
            cheapest_cost_a = current_b->cost_a;
            cheapest_cost_b = current_b->cost_b;
        }
        current_b = current_b->next;
    }
    do_move(stack_a, stack_b, cheapest_cost_a, cheapest_cost_b);
}

void do_move(t_stack_list *stack_a, t_stack_list *stack_b, int cheapest_cost_a, int cheapest_cost_b)
{
   
}