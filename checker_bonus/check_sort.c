/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:59:51 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 15:55:15 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack_list	*stack_a;
	t_stack_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	argv = check_input(argc, argv);
	stack_a = create_stack(argc, argv);
	assign_index(stack_a);
	stack_b = create_stack(0, NULL);
	read_moves(stack_a, stack_b);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}

void	read_moves(t_stack_list *stack_a, t_stack_list *stack_b)
{
	char	buffer[4];
	int		i;

	i = 0;
	while (read(0, &buffer[i], 1) == 1)
	{
		if (buffer[i] == '\n')
		{
			check_move(buffer, stack_a, stack_b);
			i = 0;
		}
		else
			i++;
	}
	if (is_sorted(stack_a) == 1 && stack_b->length == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	check_move(char *str, t_stack_list *stack_a, t_stack_list *stack_b)
{
	static int i;
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa_bonus(stack_a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb_bonus(stack_b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss_bonus(stack_a, stack_b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra_bonus(stack_a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb_bonus(stack_b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr_bonus(stack_a, stack_b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra_bonus(stack_a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb_bonus(stack_b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr_bonus(stack_a, stack_b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa_bonus(stack_b, stack_a);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb_bonus(stack_a, stack_b);
	else
		clear_and_exit(stack_a, stack_b);
	i++;
}

void clear_and_exit(t_stack_list *stack_a, t_stack_list *stack_b)
{
	clear_stack(stack_a);
	clear_stack(stack_b);
	exit(write(2, "Error\n", 6));
}