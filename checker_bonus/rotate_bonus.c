/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:29:23 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 15:34:45 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra_bonus(t_stack_list *stack_a)
{
	rotate(stack_a);
}

void	rb_bonus(t_stack_list *stack_b)
{
	rotate(stack_b);
}

void	rr_bonus(t_stack_list *stack_a, t_stack_list *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
