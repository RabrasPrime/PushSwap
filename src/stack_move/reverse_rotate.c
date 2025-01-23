/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:01:53 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/23 10:38:13 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <unistd.h>

void    revr(t_stack	**stack, int	a, char	a_or_b)
{
    t_stack	*current;

	current = *stack;
	if (!current)
		return ;
	if (current->next == *stack && current->prev == *stack)
		return ;
	if (current->next->next == *stack && current->prev == *stack)
	{
		s(stack, 0, a_or_b);
		return ;
	}
	*stack = (*stack)->prev;
	if (a && a_or_b == 'a')
		write(1, "rra\n", 4);
	if (a && a_or_b == 'b')
		write(1, "rrb\n", 4);
}
void    rrr(t_stack  **stack_a, t_stack  **stack_b)
{
	revr(stack_a, 0, 'a');
	revr(stack_b, 0, 'b');
	write(1, "rrr\n", 4);
}