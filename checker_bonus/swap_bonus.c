/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:29:46 by bbazagli          #+#    #+#             */
/*   Updated: 2024/02/05 15:35:33 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_bonus(t_stack_list *stack_a)
{
	swap(stack_a);
}

void	sb_bonus(t_stack_list *stack_b)
{
	swap(stack_b);
}

void	ss_bonus(t_stack_list *stack_a, t_stack_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
