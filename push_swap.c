#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_list	*stack_a;
	t_stack_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	check_input(argc, argv);
	stack_a = create_stack(argc, argv);
	check_double(stack_a);
    stack_b = create_stack(0, NULL);
	assign_positions(stack_a);
	sort_stack(stack_a, stack_b);
	return (0);
}

