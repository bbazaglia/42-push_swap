#include "push_swap.h"

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 7 2 1 3 6 5 4

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

	printf("After sorting:\n");
	print_stack(stack_a);
	print_stack(stack_b);

	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}