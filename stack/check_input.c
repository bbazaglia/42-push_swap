/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:22:41 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 14:41:10 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_input(int argc, char **argv)
{
	int	i;

	if (argc == 2)
		argv = check_two_args(argv);
	else if (argc >= 3)
	{
		i = 1;
		while (i < argc)
		{
			check_characters(argv[i]);
			check_limit(argv[i]);
			i++;
		}
	}
	else
		exit(write(2, "Error\n", 6));
	return (argv);
}

char	**check_two_args(char **argv)
{
	int i;

	argv = ft_split(argv[1], ' ');
	if (!argv || !*argv)
		exit(write(2, "Error\n", 6));
	i = 0;
	while (argv[i])
	{
		check_characters(argv[i]);
		check_limit(argv[i]);
		i++;
	}
	return (argv);
}

void	check_characters(char *argv)
{
	if (*argv != '+' && *argv != '-' && ft_isdigit(*argv) == 0)
		exit(write(2, "Error\n", 6));
	if ((*argv == '+' || *argv == '-') && ft_isdigit(*(argv + 1)) == 0)
		exit(write(2, "Error\n", 6));
	while (*++argv)
	{
		if (ft_isdigit(*argv) == 0)
			exit(write(2, "Error\n", 6));
	}
}

void	check_limit(char *argv)
{
	int	n;

	n = ft_atol(argv);
	if (n > INT_MAX || n < INT_MIN)
		exit(write(2, "Error\n", 6));
}

void check_duplicate(t_stack_list *stack, t_stack_node *current)
{
	t_stack_node *cur;

	cur = stack->head;
	while (cur)
	{
		if (cur != current && cur->value == current->value)
		{
			clear_stack(stack);
			exit(write(2, "Error\n", 6));
		}
		cur = cur->next;
	}
}
