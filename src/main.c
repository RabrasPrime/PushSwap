/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:36 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/28 17:01:05 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "libft.h"
#include <stdlib.h>

static void	test_arg(char	*str, char	**tab)
{
	int	i;

	if ((str[0] == '-' && str[1] == '\0') || (str[0] == '+' && str[1] == '\0'))
	{
		ft_freestr(tab);
		ft_error();
	}
	if (!(str[0] == '-' || str[0] == '+' || (str[0] >- '0' && str[0] <= '9')))
	{
		ft_freestr(tab);
		ft_error();
	}
	i = 0;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			ft_freestr(tab);
			ft_error();
		}
	}
	ft_atoi(str);
	ft_freestr(tab);
	exit(EXIT_SUCCESS);
}


