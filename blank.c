/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blank.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:30:39 by bbazagli          #+#    #+#             */
/*   Updated: 2024/01/12 15:59:30 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	change_pointer_value(int **p) 
{
	**p = 0;
	*p = NULL;
	p = NULL;
}

int	main(void)
{
	int	i;
	int	*k; 
	int **j;

	i = 10;
	k = &i;
	j = &k;

	change_pointer_value(j); 
	
	// j = ???
	// k = ???
	// i = ???

	return (0);
}