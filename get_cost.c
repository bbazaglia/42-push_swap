#include "push_swap.h"

void get_cost(t_stack_list *stack_a, t_stack_list *stack_b)
{
    int length_a;
    int length_b;
    t_stack_node *current_b;

    length_a = stack_length(stack_a);
    length_b = stack_length(stack_b);
    current_b = stack_b->head;

    while (current_b)
    {
        // calculate cost for the stack_b element get to the top of the list based on its position
        current_b->cost_b = current_b->current_pos;
        if (current_b->current_pos > length_b / 2)
            current_b->cost_b = (length_b - current_b->current_pos) * -1;

        // calculate cost for the stack_b element get to the top of the list based on its target position
        current_b->cost_a = current_b->target_pos;
        if (current_b->target_pos > length_a / 2)
            current_b->cost_a = (length_a - current_b->target_pos) * -1;

        current_b = current_b->next;
    }
}

/* About the cost:

(1) Why divide the length by 2?
- If the element's position is less than the middle position of the stack (it is in the top half) opt for rotate the stack.
- If the element's position is greater than the middle position of the stack (it is in the bottom half) opt for reverse rotate the stack.

* Note about rotate and reverse rotate:
rotate moves the top element to the bottom of the stack 
reverse rotate moves the bottom element to the top of the stack

* Example: stack with 6 elements (mid position = 3)
stack:  [1] 7
        [2] 5
        [3] 3
        [4] 1
        [5] 9
        [6] 8

If our target element is 5, it's position is 2 (it is in the top half).
    By rotating the stack, we would have to bring the top element down once.
    By reverse rotating the stack, we would have to bring the bottom element up 5 times.


(2) Why assign a negative value to reverse rotate?
To distinguish between regular rotation and reverse rotation during the execution of an action sequence.
This optimizes simultaneous operations.

* Example: 
If the costs of stack A and stack B have the same sign (both positive or both negative), both stacks require the same type of operation.
If the cost is negative, it's a reverse rotate operation, and if the cost is positive, it's a regular rotate operation.
If the stack A has the cost of -1 and the stack B also has the cost of 1, we can execute rrr instead of rra + rrb.

*/