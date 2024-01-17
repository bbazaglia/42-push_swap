#include "push_swap.h"

void assign_position(t_stack_list *stack) 
{
    t_stack_node *current;
    int i;
    
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

t_stack_node* merge_sorted_lists(t_stack_node* a, t_stack_node* b) 
{
    t_stack_node* result;

    result = NULL;

    // base cases: if the one list is empty, return the other list
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    
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
    return result;
}

void find_middle_and_split(t_stack_node* source, t_stack_node** front_ref, t_stack_node** back_ref) 
{
    t_stack_node* fast;
    t_stack_node* slow;

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

void merge_sort(t_stack_node** head_ref) 
{
    // create a local pointer to the head of the list
    t_stack_node* head = *head_ref;

    // create pointers that will eventually store the two halves of the list
    t_stack_node* a;
    t_stack_node* b;
    
    if ((head == NULL) || (head->next == NULL)) 
        return;
    
    // split the list into two halves
    find_middle_and_split(head, &a, &b);
    
    // recursively sort the sublists
    merge_sort(&a);
    merge_sort(&b);
    
    // merge the sorted sublists
    *head_ref = merge_sorted_lists(a, b);
}