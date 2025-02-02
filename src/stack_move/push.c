/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:36:51 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/02 23:12:07 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <unistd.h>

static void initiate_pointer(t_stack **end, t_stack **start, t_stack **upcomming, t_stack **stack)
{
    *end = (*stack)->prev;
    *start = *stack;
    *upcomming = (*stack)->next;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current;
    t_stack *last;
    t_stack *upcomming;
    int a;

    if (!(*stack_b))
        return ;
    a = 1;
    if ((*stack_b)->next == *stack_b && (*stack_b)->prev == *stack_b)
        a = 0;
    initiate_pointer(&last, &current, &upcomming, stack_b);
    current->next = *stack_a;
    (*stack_a)->prev->next = current;
    current->prev = (*stack_a)->prev;
    (*stack_a)->prev = current;
    *stack_a = current;
    if (!a)
        *stack_b = NULL;
    else
    {
        *stack_b = upcomming;
        (*stack_b)->prev = last;
        last->next = *stack_b;
    }
    write(1, "pa\n", 3);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current;

    if (!(*stack_a))
        return ;
    current = *stack_a;
    *stack_a = (*stack_a)->next;
    (*stack_a)->prev = current->prev;
    (*stack_a)->prev->next = *stack_a;
    if (!(*stack_b))
    {
        current->prev = current;
        current->next = current;
        *stack_b = current;
    }
    else
    {
        current->next = *stack_b;
        current->prev = (*stack_b)->prev;
        (*stack_b)->prev = current;
        current->prev->next = current;
        *stack_b = current;
    }
    write(1, "pb\n", 3);
}
