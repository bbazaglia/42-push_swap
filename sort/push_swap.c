/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:25:38 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 14:31:38 by bbazagli         ###   ########.fr       */
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
	stack_b = create_stack(0, NULL);
	check_double(stack_a);
	assign_index(stack_a);
	sort_stack(stack_a, stack_b);
 	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}
