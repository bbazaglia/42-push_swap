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
		argv = check_two_args(argc, argv);
	else if (argc >= 3)
	{
		i = 1;
		while (i < argc)
		{
			if (check_characters(argv[i]) || check_limit(argv[i]))
				exit(write(2, "Error\n", 6));
			i++;
		}
	}
	else
		exit(write(2, "Error\n", 6));
	return (argv);
}

char	**check_two_args(int argc, char **argv)
{
	int i;

	char **split;
	split = ft_split(argv[1], ' ');
	if (!split || !*split)
		exit(write(2, "Error\n", 6));
	i = 0;
	while (split[i])
	{
		if (check_characters(split[i]) || check_limit(split[i]))
		{
			free_args(argc, split);
			exit(write(2, "Error\n", 6));
		}
		i++;
	}
	return (split);
}

int	check_characters(char *argv)
{
	if (*argv != '+' && *argv != '-' && ft_isdigit(*argv) == 0)
		return (1);
	if ((*argv == '+' || *argv == '-') && ft_isdigit(*(argv + 1)) == 0)
		return (1);
	while (*++argv)
	{
		if (ft_isdigit(*argv) == 0)
			return (1);
	}
	return (0);
}

int	check_limit(char *argv)
{
	int	n;

	n = ft_atol(argv);
	if (n > INT_MAX || n < INT_MIN)
		return (1);
	return (0);
}

void check_duplicate(t_stack_list *stack, t_stack_node *current, int argc, char **argv)
{
	t_stack_node *cur;

	cur = stack->head;
	while (cur)
	{
		if (cur != current && cur->value == current->value)
		{
			clear_stack(stack);
			free_args(argc, argv);
			exit(write(2, "Error\n", 6));
		}
		cur = cur->next;
	}
}
