/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:01:57 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/23 10:36:15 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <unistd.h>

void    r(t_stack  **stack, int a, char a_or_b)
{
    t_stack *current;

    current = *stack;
    if (!current)
        return ;
    if (current->next == *stack && current->prev == *stack)
        return ;
    if (current->next->next == *stack && current->prev == *stack)
    {
        s(stack, 0, a_or_b);
        return ;
    }
    *stack = (*stack)->next;
    if (a && a_or_b == 'a')
        write(1, "ra\n",3);
    else if (a && a_or_b == 'b')
        write(1, "rb\n",3);
}

void    rr(t_stack  **stack_a, t_stack  **stack_b)
{
    r(stack_a, 0, 'a');
    r(stack_b, 0, 'b');
    write(1, "rr\n", 3);
}