/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:45:56 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/28 15:54:50 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_freestr(char	**str)
{
	int	i;
	
	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}