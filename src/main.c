/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:36 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/30 15:52:31 by tjooris          ###   ########.fr       */
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

static	is_orderer(t_stack	*stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current->next != stack_a)
	{
		if (current->number > current->next->number)
			return ;
			current = current->next;
	}
	exit(EXIT_SUCCESS);
}

int	main(int	argc, char	**argv)
{
	char	**tab;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argv[1] && !argv[1][0])
		ft_error();
	stack_a = NULL;
	tab = NULL;
	tab = args_handler(&argc, argv);
	stack_a = stack_init(stack_a, tab);
	is_orderer(stack_a);
	stack_b = NULL;
	if (argc <= 3)
		sort_three(&stack_a);
	else if (argc <= 5)
		sort_five(&stack_a, &stack_b);
	else
	{
		init(stack_a);
		sort_number(&stack_a, &stack_b);
	}
	ft_freestr(tab);
	ft_freestack(&stack_a, stacklen(stack_a));
}
