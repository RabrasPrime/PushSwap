/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:39:32 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/29 17:13:36 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

typedef	struct s_stack
{
	int	number;
	int	index;
	int value;
	struct s_stack	*next;
	struct s_stack	*prev;
	int			value;
	int			sa;
	int			sb;
	int			ra;
	int			rb;
	int			rra;
	int			rrb;
	int			move;
}	t_stack;

typedef struct s_sequence
{
	int	current_length;   
	int	max_length;       
	int	current_start;    
	int	max_start;        
	int	marked_start;     
}	t_sequence;

typedef struct s_max
{
	int	position;
	int	stack_size;
}	t_max;

/*=-=-=-=-=-=-=-=-=-MOVE-=-=-=-=-=-=-=-=-=*/

void	pa(t_stack	**stack_a, t_stack	**stack_b);
void	pb(t_stack  **stack_a, t_stack  **stack_b);
void    revr(t_stack	**stack, int	a, char	a_or_b);
void    rrr(t_stack  **stack_a, t_stack  **stack_b);
void    r(t_stack  **stack, int a, char a_or_b);
void    rr(t_stack  **stack_a, t_stack  **stack_b);
void    s(t_stack  **stack, int a, char a_or_b);
void    ss(t_stack  **stack_a, t_stack  **stack_b);

/*=-=-=-=-=-=-=-=-=-INDEX-=-=-=-=-=-=-=-=-=*/

void	init(t_stack	*stack);
int	is_max(t_stack	*stack_a, t_stack	*second);

/*=-=-=-=-=-=-=-=-=-STACK_FUNCTIONS-=-=-=-=-=-=-=-=-=*/

int		*stackdup(int	*tab, t_stack	*stack);
t_stack	*create_stack(int value);
t_stack	*stack_init(t_stack	*stack, char **array);
int	stacklen(t_stack	*stack);
void	prepare_stack(t_stack	**stack_a, t_stack	**current);

/*=-=-=-=-=-=-=-=-=-SORT-=-=-=-=-=-=-=-=-=*/

void	sort_three(t_stack	**stack);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_number(t_stack	**stack_a, t_stack	**stack_b);

/*=-=-=-=-=-=-=-=-=-SEQUENCE-=-=-=-=-=-=-=-=-=*/

void	mark(t_stack	**stack_a, t_sequence	*seq);
t_sequence	*sequence(t_stack	**stack);

/*=-=-=-=-=-=-=-=-=-ARG-=-=-=-=-=-=-=-=-=*/

char	**args_handler(int	*ac, char	**av);

/*=-=-=-=-=-=-=-=-=-MOVE-=-=-=-=-=-=-=-=-=*/

void	initiate_move(t_stack	**stack_a, int	n);

#endif