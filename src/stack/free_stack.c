/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:24:30 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/02 23:10:08 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>  

void	ft_freestack(t_stack	**stack, int size)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	while (i < size - 1)
	{
		current = current->next;
		free(current->prev);
		i++;
	}
	free(current);
}
