/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:06:59 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/29 15:39:52 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	max_init(t_max	**max, t_stack	**stack_a)
{
	*max = malloc(sizeof(t_max));
	(*max)->position = 2147483647;
	(*max)->stack_size = stacklen(*stack_a);
}

void	prepare_stack(t_stack	**stack_a, t_stack	**current)
{
	t_max	*max;
	int		i;

	max_init(&max, stack_a);
	i = 
}