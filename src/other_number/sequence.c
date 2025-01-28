/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:09:37 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/28 10:37:20 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

t_sequence	*alloc_sequence(t_sequence	**seq)
{
	(*seq) = malloc(sizeof(t_sequence));
	if (!(*seq))
		return (NULL);
	(*seq)->max_length = 0;
	(*seq)->current_length = 1;
	return (*seq);
}
void	initiate_mark(t_stack	**stack_a)
{
	t_stack	*current;
	
	current = *stack_a;
	while (current->next != stack_a)
	{
		current->value = 0;
		current = current->next;
	}
	current->value = 0;
}
void	mark(t_stack	**stack_a, t_sequence	*seq)
{
	t_stack	*current;
	t_stack	*next;
	int		i;

	initiate_mark(stack_a);
	i = 0;
	current = *stack_a;
	while(i++ < seq->max_start)
		next = current->next;
	current->value = 1;
	i = current->index;
	next = current->next;
	seq->marked_start = current->index;
	while (next->next != *stack_a)
	{
		if (i == next->index - 1)
		{
			next->value = 1;
			i = next->index;
		}
		next = next->next;
	}
	if (i == next->value - 1)
		next->value = 1;
}

void	create_seq(t_stack	*current, t_sequence	**seq, int i, t_stack	**stack)
{
	
}