/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:09:55 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/30 13:03:30 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	move_revr(t_stack	**stack_a, t_stack	**stack_b, t_stack	**current)
{
	while ((*current)->rra && (*current)->rrb)
	{
		rrr(stack_a, stack_a);
		(*current)->rra--;
		(*current)->rrb--;
	}
	while ((*current)->rra)
	{
		revr(stack_a, 1, 'a');
		(*current)->rra--;
	}
	while ( ((*current)->rrb))
	{
		revr(stack_b, 1, 'b');
		(*current)->rrb--;
	}
	while ((*current)->rb)
	{
		r(stack_b, 1, 'b');
		(*current)->rb--;
	}
	pa(stack_a, stack_b);
}
static void	move_r(t_stack	**stack_a, t_stack	**stack_b, t_stack	**current)
{
	while ((*current)->ra && (*current)->rb)
	{
		rr(stack_a, stack_b);
		(*current)->ra--;
		(*current)->rb--;
	}
	while ((*current)->ra)
	{
		r(stack_a, 1, 'a');
		(*current)->ra--;
	}
	while ((*current)->rb)
	{
		r(stack_b, 1, 'b');
		(*current)->rb--;
	}
	while ((*current)->rrb)
	{
		revr(stack_b, 1, 'b');
		(*current)->rrb--;
	}
	pa(stack_a, stack_b);
}
void	move(t_stack	**stack_a, t_stack	**stack_b, t_stack	**current)
{
	if ((*current)->move == 1)
		move_revr(stack_a, stack_a, current);
	else if ((*current)->move == 2)
		move_r(stack_a, stack_b, current);
}