/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:29:24 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/29 18:34:32 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	push_best(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack	*current;
	t_stack	*save;
	int		max;

	max = 2147483647;
	current = *stack_b;
	while (current->next != stack_b)
	{
		if (current->sa + current->sb + current->ra 
			+ current->rb + current->rra + current->rrb < max)
		{
			max = current->sa + current->sb + current->ra  + current->rb + current->rra + current->rrb;
			save = current;
		}
	}
	if (current->sa + current->sb + current->ra 
		+ current->rb + current->rra + current->rrb < max)
	{
		max = current->sa + current->sb + current->ra  + current->rb + current->rra + current->rrb;
		save = current;
	}
	
}

void	find_push(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack	*current_b;
	int		i;
	int		size;

	current_b = *stack_b;
	i = 0;
	size = stacklen(*stack_b);
	while (current_b->next != *stack_b)
	{
		if (i <= size / 2)
			current_b->rb = i;
		else
			current_b->rrb = size -1;
		prepare_stack(stack_a, &current_b);
		i++;
		current_b = current_b->next;
	}
	if (i <= size / 2)
		current_b->rb = i;
	else
		current_b->rrb = size - i;
	prepare_stack(stack_a, &current_b);
	
}
