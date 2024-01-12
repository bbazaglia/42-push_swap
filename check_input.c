#include "push_swap.h"

void	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		exit(0);
	while (argv)
	{
		check_characters(argv[i]);
		check_limit(argv[i]);
		i++;
	}
}

void	check_characters(char *argv)
{
	if (*argv != '+' && *argv != '-' && !isdigit(*argv))
		print_error();
	if ((*argv == '+' || *argv == '-') && !isdigit(*(argv + 1)))
		print_error();
	while (*++argv)
	{
		if (!isdigit(*argv))
			print_error();
	}
}

void	check_limit(char *argv)
{
	int	n;

	n = ft_atol(argv);
	if (n > INT_MAX || n < INT_MIN)
		print_error();
}

void	check_double(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				print_error();
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}