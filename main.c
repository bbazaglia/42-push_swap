#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	check_input(argc, argv);
	stack_a = initialize_stack(argc, argv);
	check_double(stack_a);

	// third part: sort the stack

	return (0);
}

