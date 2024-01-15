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

void	check_double(t_stack_list *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	tmp = stack->head;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				print_error();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}