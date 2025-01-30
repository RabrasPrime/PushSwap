/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:36 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/30 13:12:05 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "libft.h"
#include <stdlib.h>

void	initiate_move(t_stack	**stack_a, int	n)
{
	t_stack	*current;

	current = *stack_a;
	while (current->next != *stack_a)
	{
		current->sa = n;
		current->sb = n;
		current->ra = n;
		current->rb = n;
		current->rra = n;
		current->rrb = n;
		current->move = n;
	}
	current->sa = n;
	current->sb = n;
	current->ra = n;
	current->rb = n;
	current->rra = n;
	current->rrb = n;
}
