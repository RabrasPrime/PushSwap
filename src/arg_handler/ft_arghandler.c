/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arghandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:03:07 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/02 23:01:17 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "ft_pushswap.h"

static void	test_arg(char *str, char **tab)
{
	int	i;

	if ((str[0] == '-' && str[1] == '\0') || (str[0] == '+' && str[1] == '\0'))
	{
		ft_freestr(tab);
		ft_error();
	}
	if (!(str[0] == '-' || str[0] == '+' || (str[0] >= '0' && str[0] <= '9')))
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
	ft_freestr(tab);
	exit(EXIT_SUCCESS);
}

static char	**handle_one_arg(int *ac, char **av)
{
	char	**tab;

	tab = ft_split(av[1], ' ');
	if (!tab)
		exit(EXIT_FAILURE);
	if (!tab[1])
		test_arg(tab[0], tab);
	*ac = ft_tablen(tab);
	return (tab);
}

static char	**handle_multiple_arg(int *ac, char **av)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (*ac));
	if (!tab)
		ft_error();
	while (i < *ac - 1)
	{
		tab[i] = ft_strdup(av[i + 1]);
		i++;
	}
	tab[i] = NULL;
	(*ac)--;
	return (tab);
}

char	**args_handler(int *argc, char **argv)
{
	char	**tab;

	if (*argc < 2)
		exit(EXIT_FAILURE);
	else if (*argc == 2)
		tab = handle_one_arg(argc, argv);
	else
		tab = handle_multiple_arg(argc, argv);
	return (tab);
}

