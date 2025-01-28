/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:24:06 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/28 14:54:27 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <unistd.h>

static void	first_index(t_stack	**stack, t_stack	*current, t_max	*max, int i)
{
	if (current->index == 0)
	{
		if (max->position <= max->stack_size /2)
		{
			while (i++ < max->nb)
				r(stack, 1, 'a');
		}
		else
		{
			while (i++ < max->stack_size - max->position)
				revr(stack, 1, 'a');
		}
	}
}
static void	reorg(t_stack	**stack, int	stack_size, int	index)
{
	t_stack	*current;
	int		i;
	int		j;

	current = *stack;
	i = 0;
	j = 0;
	while ( current->next != *stack )
	{
		if (current-index == index)
		{
			if (i <= stack_size / 2)
				while ( j++ < i )
					r(stack, 1, 'a');
			else
				while (j++ < stack_size - i)
					revr(stack, 1, 'a');
			return ;
		}
		i++;
		current = current->next;
	}
	first_index(stack, current, &(t_max){i, stack_size}, j);
}

static void	need_sa(t_stack	**stack, t_sequence **seq)
{
	t_sequence	*fake_sequence;

	s(stack, 0, 'a');
	fake_sequence = sequence(stack);
	if (fake_sequence->max_length > (*seq)->max_length)
	{
		write(1, "sa\n", 3);
		mark(stack, fake_sequence);
		free(*seq);
		*seq = fake_sequence;
	}
	else
	{
		free(fake_sequence);
		s(stack, 0, 'a');
	}
}
