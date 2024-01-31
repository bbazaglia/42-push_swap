#include "push_swap.h"

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 7 2 1 3 6 5 4

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 37 46 76 30 69 0 50 32 83 90 61 8 17 45 15 5 26 22 1 58 85 66 3 60 77 52 56 36 96 67 14 10 65 86 92 11 79 84 63 68 97 39 78 51 94 2 95 6 23 53 72 41 12 19 91 38 29 47 44 33 18 34 4 55 73 9 16 89 42 82 81 98 71 28 13 20 80 62 27 40 21 31 88 24 43 87 48 75 70 99 49 57 25 74 35 93 59 54 64 7
// 10 90 21 1 5 7 9 0 -1 -4 -7 -52 52 29 30 26 -25 789 12 -27
// 53 27 55 28 81 38 17 94 31 5 46 21 3 2 7 71 45 33 -1

int	main(int argc, char **argv)
{
	t_stack_list	*stack_a;
	t_stack_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	argv = check_input(argc, argv);
	stack_a = create_stack(argc, argv);
	stack_b = create_stack(0, NULL);
	check_double(stack_a);
	assign_index(stack_a);
	sort_stack(stack_a, stack_b);

	// printf("After sorting:\n");
	// print_stack(stack_a);
	// print_stack(stack_b);

	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}