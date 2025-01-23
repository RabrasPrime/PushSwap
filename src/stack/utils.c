/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:11 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/23 15:16:32 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "libft.h"
#include <stdlib.h>

void	add_stack(t_stack *stack, t_stack *add)
{
	t_stack	*top;
	
	top = stack;
	while (top->next != stack)
	{
		if (top->number == add->number)
			return ;
		top = top->next;
	}
	if (top->number == add->number)
		return ;
	if (stack->next == stack && stack->prev == stack)
	{
		stack->next = add;
		stack->prev = add;
		add->next = stack;
		add->prev = stack;
			return ;
	}
	top = stack;
	add->prev = top->prev;
	top->prev->next = add;
	top->prev = add;
	add->next = top;
	
}

t_stack	*create_stack(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->number = value;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

t_stack	stack_init(t_stack	*stack, char **array)
{
	int	i;

	stack = create_stack(ft_atoi(array[0]));
	stack->next = stack;
	stack->prev = stack;
	i = 1;
}