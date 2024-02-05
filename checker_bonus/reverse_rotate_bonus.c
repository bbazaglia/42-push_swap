/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:29:20 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 15:34:40 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra_bonus(t_stack_list *stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb_bonus(t_stack_list *stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr_bonus(t_stack_list *stack_a, t_stack_list *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
