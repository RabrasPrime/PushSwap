/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:29:24 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/29 14:23:50 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	find_push(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack	*current;
	int		i;
	int		size;

	current = *stack_b;
	i = 0;
	size = stacklen(*stack_b);
	while (current->next != *stack_b)
	{
		if (i <= size / 2)
			current->rb = i;
		else
			current->rrb = size -1;
		
	}
	
}
