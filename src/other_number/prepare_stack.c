/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:06:59 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/02 23:07:16 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

void find_best(t_max **max, int i, t_stack **stack_b, t_stack *stack_a)
{
    int last_max;

    if ((*stack_b)->number < stack_a->number)
    {
        last_max = stack_a->index - (*stack_b)->index;
        if (last_max < (*max)->position)
        {
            (*max)->position = last_max;
            if (i <= (*max)->stack_size / 2)
            {
                (*stack_b)->move = 1;
                (*stack_b)->ra = 1;
            }
            else
            {
                (*stack_b)->move = 2;
                (*stack_b)->rra = (*max)->stack_size - i;
            }
        }
    }
}

void loop_find_best(t_stack **stack_a, t_stack **stack_b, t_max **max)
{
    t_stack *current_a;
    int i;

    current_a = *stack_a;
    i = 0;
    while (current_a->next != *stack_a)
    {
        find_best(max, i, stack_b, current_a);
        current_a = current_a->next;
        i++;
    }
    find_best(max, i, stack_b, *stack_a);
}

static void max_init(t_max **max, t_stack **stack_a)
{
    *max = malloc(sizeof(t_max));
    (*max)->position = 2147483647;
    (*max)->stack_size = stacklen(*stack_a);
}

void prepare_stack(t_stack **stack_a, t_stack **current)
{
    t_max *max;
    int i;

    max_init(&max, stack_a);
    i = is_max(*stack_a, *current);
    if (i >= 0 && i <= max->stack_size / 2)
    {
        (*current)->move = 2;
        (*current)->ra = i + 1;
        free(max);
        return;
    }
    else if (i >= 0 && i > max->stack_size - i - 1)
    {
        (*current)->move = 2;
        (*current)->rra = max->stack_size - i - 1;
        free(max);
        return;
    }
    loop_find_best(stack_a, current, &max);
    free(max);
}
