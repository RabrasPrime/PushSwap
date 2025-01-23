/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:07:46 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/23 16:59:20 by tjooris          ###   ########.fr       */
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

