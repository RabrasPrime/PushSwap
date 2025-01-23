/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:39:32 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/23 17:09:09 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

typedef	struct s_stack
{
	int	number;
	int	index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


void	initiate_pointer(t_stack **end, t_stack **start, t_stack **upcomming, t_stack **stack);
void	pa(t_stack	**stack_a, t_stack	**stack_b);
void	pb(t_stack  **stack_a, t_stack  **stack_b);
void    revr(t_stack	**stack, int	a, char	a_or_b);
void    rrr(t_stack  **stack_a, t_stack  **stack_b);
void    r(t_stack  **stack, int a, char a_or_b);
void    rr(t_stack  **stack_a, t_stack  **stack_b);
void    s(t_stack  **stack, int a, char a_or_b);
void    ss(t_stack  **stack_a, t_stack  **stack_b);

#endif