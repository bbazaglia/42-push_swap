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
	{
		argv = ft_split(argv[1], ' ');
		if (!argv || !*argv)
			print_error();
		i = 0;
		while (argv[i])
		{
			check_characters(argv[i]);
			check_limit(argv[i]);
			i++;
		}
	}
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
		print_error();
	return (argv);
}

void	check_characters(char *argv)
{
	if (*argv != '+' && *argv != '-' && ft_isdigit(*argv) == 0)
		print_error();
	if ((*argv == '+' || *argv == '-') && ft_isdigit(*(argv + 1)) == 0)
		print_error();
	while (*++argv)
	{
		if (ft_isdigit(*argv) == 0)
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

// to do: check for doubles during sort
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
