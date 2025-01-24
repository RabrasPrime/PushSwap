/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:07:46 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/24 10:37:22 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	check_order(t_stack	*stack)
{
	if ((stack->number < stack->next->number)
		&& (stack->next->number < stack->prev->number))
		return (1);
	else if ((stack->number > stack->next->number)
		&& (stack->next->number < stack->prev->number)
		&& (stack->prev->number > stack->number))
		return (2);
	else if ((stack->number > stack->next->number)
		&& (stack->next->number > stack->prev->number)
		&& (stack->prev->number < stack->number))
		return (3);
	else if ((stack->number > stack->next->number)
		&& (stack->next->number < stack->prev->number)
		&& (stack->prev->number < stack->number))
		return (4);
	else if ((stack->number < stack->next->number)
		&& (stack->next->number > stack->prev->number)
		&& (stack->prev->number > stack->number))
		return (5);
	else
		return (6);
}

void	sort_three(t_stack	**stack)
{
	if (stacklen(*stack) == 2 && (*stack)->number > (*stack)->next->number)
	{
		s(stack, 1, 'a');
		return ;
	}
	if (check_order(*stack) == 1)
		return ;
	else if (check_order(*stack) == 2)
		s(*stack, 1, 'a');
	else if (check_order(*stack) == 3)
	{
		r(*stack, 1, 'a');
		s(*stack, 1, 'a');
	}
	else if (check_order(*stack) == 4)
		r(*stack, 1, 'a');
	else if (check_order(*stack) == 5)
	{
		s(*stack, 1, 'a');
		r(*stack, 1, 'a');
	}
	else
		revr(*stack, 1, 'a');
}
