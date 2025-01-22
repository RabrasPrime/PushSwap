/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:02:04 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/22 19:12:03 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <unistd.h>

void    s(t_stack  **stack, int a, char a_or_b)
{
    t_stack *current;
    int     tmp;

    current = *stack;
    tmp = current->number;
    current->number = current->next->number;
    current->next->number = tmp;
    tmp = current->index;
    current->index = current->next->index;
    current->next->index = tmp;
    if (a && a_or_b == 'a')
        write(1, "sa\n", 3);
    if (a && a_or_b == 'b')
        write(1, "sb\n", 3);
}

void    ss(t_stack  **stack_a, t_stack  **stack_b)
{
    s(stack_a, 0, 'a');
    s(stack_b, 0, 'b');
    write(1, "ss\n", 3);
}