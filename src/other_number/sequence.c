/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:09:37 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/02 23:08:35 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

static t_sequence	*alloc_sequence(t_sequence	**seq)
{
	(*seq) = malloc(sizeof(t_sequence));
	if (!(*seq))
		return (NULL);
	(*seq)->max_length = 0;
	(*seq)->current_length = 1;
	return (*seq);
}

static void	initiate_mark(t_stack	**stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (current->next != *stack_a)
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
	while (i++ < seq->max_start)
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
	if (i == next->index - 1)
		next->value = 1;
}

static void	create_seq(t_stack	*current, t_sequence	**seq, t_stack	**stack)
{
	t_stack	*cur;
	int		prev;

	cur = current->next;
	prev = current->index;
	while (cur->next != *stack)
	{
		if (prev == cur->index - 1)
		{
			(*seq)->current_length++;
			prev = cur->index;
		}
		cur = cur->next;
	}
	if (prev == cur->index - 1)
		(*seq)->current_length++;
	if ((*seq)->current_length > (*seq)->max_length)
	{
		(*seq)->max_length = (*seq)->current_length;
		(*seq)->max_start = (*seq)->current_start;
	}
}

t_sequence	*sequence(t_stack	**stack)
{
	t_sequence	*seq;
	t_stack		*current;

	seq = alloc_sequence(&seq);
	if (!seq)
		return (NULL);
	current = *stack;
	while (current->next != *stack)
	{
		create_seq(current, &seq, stack);
		current = current->next;
	}
	return (seq);
}

