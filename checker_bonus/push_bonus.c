/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:29:16 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 15:35:01 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa_bonus(t_stack_list *stack_b, t_stack_list *stack_a)
{
	push(stack_b, stack_a);
}

void	pb_bonus(t_stack_list *stack_a, t_stack_list *stack_b)
{
	push(stack_a, stack_b);
}
