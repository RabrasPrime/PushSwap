/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:08:05 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/24 18:03:59 by tjooris          ###   ########.fr       */
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

int	push_4(t_stack	**stack_a, t_stack	**stack_b, int size)
{
	if ((*stack_b)->number > (*stack_a)->prev->number)
	{
		pa(stack_a, stack_b);
		r(stack_a, 1, 'a');
	}
	else if ((*stack_a)->number < (*stack_a)->number)
		pa(stack_a, stack_b);
	else if (((*stack_b)->number > (*stack_a)->number)
		&& (*stack_b)->number > (*stack_a)->next->number)
		{
			pa(stack_a, stack_b);
			s(stack_a, 1, 'a');
		}
		else if (((*stack_a)->prev->number > (*stack_b)->number)
			&& (*stack_b)->number > (*stack_a)->prev->prev->number)
			{
				revr(stack_a, 1, 'a');
				pa(stack_a, stack_b);
				if (is_five(stack_a, stack_b, size))
					return (0);
				r(stack_a, 1, 'a');
				r(stack_a, 1, 'a');
			}
			return (1);
}

