/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:08:05 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/24 15:54:05 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	is_five(t_stack	**stack_a, t_stack	**stack_b, int	n)
{
	if (n == 5)
	{
		if(((*stack_b)->number < (*stack_a)->number)
			&& ((*stack_b)->number > (*stack_a)->number))
		{
			p(stack_a, stack_b, 'a');
			revr(stack_a, 1, 'a');
			revr(stack_a, 1, 'a');
			return (1);
		}
	}
	return (0);
}

