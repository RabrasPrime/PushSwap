/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:11 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/30 16:43:40 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "libft.h"
#include <stdlib.h>

static void	add_stack(t_stack *stack, t_stack *add)
{
	t_stack	*top;
	
	top = stack;
	while (top->next != stack)
	{
		if (top->number == add->number)
			exit(-1) ;
		top = top->next;
	}
	if (top->number == add->number)
		exit(-1) ;
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

int	stacklen(t_stack	*stack)
{
	t_stack	*current;
	int		i;

	if (!stack)
		return (0);
	if (stack->next == stack && stack->prev == stack)
		return (1);
	if (stack->next->next == stack || stack->prev == stack)
		return (2);
	current = stack;
	i = 0;
	while (current->next != stack)
	{
		current = current->next;
		i++;
	}
	return (i);
	
}

int	*stackdup(int	*tab, t_stack	*stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = stack;
	tab = (int *)malloc(sizeof(int) * stacklen(stack));
	while (current->next != stack)
	{
		tab[i++] = current->number;
		current = current->next;
	}
	tab[i] = current->number;
	return (tab);
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

t_stack	*stack_init(t_stack	*stack, char **array)
{
	int	i;

	stack = create_stack(ft_atoi(array[0]));
	if (!stack)
		error();
	stack->next = stack;
	stack->prev = stack;
	i = 1;
	while (array[i])
		add_stack(stack, create_stack(ft_atoi(array[i++])));
	return (stack);
}
