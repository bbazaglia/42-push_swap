#include "push_swap.h"

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 1 4 5 7 2 3

int	main(int argc, char **argv)
{
	t_stack_list	*stack_a;
	t_stack_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	check_input(argc, argv);
	stack_a = create_stack(argc, argv);
	stack_b = create_stack(0, NULL);
	
	check_double(stack_a);
	assign_index(stack_a);
	sort_stack(stack_a, stack_b);
	t_stack_node *temp = stack_a->head;
	printf("\nStack A after sorting:\n");
	while (temp)
	{
		printf("index: %d and value: %d\n", temp->index, temp->value);
		temp = temp->next;
	}
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}