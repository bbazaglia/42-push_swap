#include "push_swap.h"

// the first element becomes the last one
void rotate(t_stack_list *stack)
{
   t_stack_node *tmp;

   // check if the stack is empty or contains only one node. 
   if (stack->head == NULL || stack->head->next == NULL)
       return;

   // store the first node in the temporary pointer
   tmp = stack->head;

   // move the head pointer to the second node
   stack->head = stack->head->next;

   // disconnect the first node from the rest of the list
   stack->head->prev = NULL;

   // connect the first node to the end of the list
   stack->tail->next = tmp;
   tmp->prev = stack->tail;

   // disconnect the first node from the rest of the list again
   tmp->next = NULL;

   // update the tail pointer to the first node
   stack->tail = tmp;
}

void ra(t_stack_list *stack_a)
{
   rotate(stack_a);
   write(1, "ra\n", 3);
}

void rb(t_stack_list *stack_b)
{
   rotate(stack_b);
   write(1, "rb\n", 3);
}

void rr(t_stack_list *stack_a, t_stack_list *stack_b)
{
   rotate(stack_a);
   rotate(stack_b);
   write(1, "rr\n", 3);
}