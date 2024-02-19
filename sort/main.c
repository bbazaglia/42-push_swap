/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:46:24 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/19 10:52:25 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_list	*stack_a;
	t_stack_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	argv = check_input(argc, argv);
	stack_a = create_stack(argc, argv);
	assign_index(stack_a, argc, argv);
	stack_b = create_stack(0, NULL);
	sort_stack(stack_a, stack_b);
	free_args(argc, argv);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}
