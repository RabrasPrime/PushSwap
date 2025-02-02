/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_max_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:44:24 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/02 23:05:49 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static int	find_smallest_index(t_stack *stack_a, t_stack *b, int max, t_stack *current)
{
	int	index;
	int	i;

	i = 0;
	index = -1;
	while (current->next != stack_a)
	{
		if (b->number > current->number)
		{
			if (current->number > max)
			{
				max = current->number;
				index = i;
			}
		}
		current = current->next;
		i++;
	}
	if (b->number > current->number)
		if (current->number > max)
			index = i;
	return (index);
}

int	is_max(t_stack *stack_a, t_stack *second)
{
	t_stack	*current;
	int		max;

	current = stack_a;
	while (current->next != stack_a)
	{
		if (current->number > second->number)
			return (-1);
		current = current->next;
	}
	if (current->number > second->number)
		return (-1);
	current = stack_a;
	max = -2147483648;
	return (find_smallest_index(stack_a, second, max, current));
}
