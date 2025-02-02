/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:13:00 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/02 23:16:40 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "libft.h"

static void prepare_index(int max, t_stack **stack, int a)
{
    if (a)
    {
        while ((*stack)->index != max)
            *stack = (*stack)->next;
    }
    else
    {
        while ((*stack)->index != max)
            *stack = (*stack)->prev;
    }
}

static int part(t_stack *stack, int *tab, int pos_start, int pos_end)
{
    int i;
    int j;
    t_stack *start;
    t_stack *end;

    i = 0;
    j = 0;
    while (pos_end - j > pos_start + i)
    {
        while (tab[pos_start] > tab[pos_start + i])
            i++;
        while (tab[pos_end] < tab[pos_end - j])
            j++;
        if (pos_end - j < pos_start + i)
            break;
        ft_swap(&tab[pos_start + i], &tab[pos_end - j]);
        start = stack;
        end = stack->prev;
        prepare_index(pos_start + i, &start, 1);
        prepare_index(pos_end - j, &end, 0);
        ft_swap(&start->index, &end->index);
    }
    ft_swap(&tab[pos_start], &tab[pos_end - j]);
    return (pos_end - j);
}

static void quicksort(t_stack *stack, int *tab, int pos_start, int pos_end)
{
    int pillar;

    if (pos_start < pos_end)
    {
        pillar = part(stack, tab, pos_start, pos_end);
        quicksort(stack, tab, pos_start, pillar - 1);
        quicksort(stack, tab, pillar + 1, pos_end);
    }
}

void init(t_stack *stack)
{
    int *tab;
    int i;
    t_stack *stack_c;

    tab = NULL;
    tab = stackdup(tab, stack);
	stack_c = stack;
    i = 0;
    while (stack_c->next != stack)
    {
        stack_c->index = i++;
        stack_c = stack_c->next;
    }
    stack_c->index = i;
    quicksort(stack, tab, 0, stacklen(stack) - 1);
    stack_c = stack;
    free(tab);
}
