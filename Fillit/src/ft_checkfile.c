/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:59:49 by romoldov          #+#    #+#             */
/*   Updated: 2018/01/18 19:00:25 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "../libft/libft.h"

int	ft_checkfile(char *str)
{
	int i;

	if ((ft_strlen(str) + 1) % 21 != 0)
		return (0);
	if (ft_strlen(str) > 550)
		return (0);
	i = 0;
	while (ft_checkgrid(&str[i]) && ft_checktetro(&str[i]))
	{
		if (i + 20 == ft_strlen(str))
			return (1);
		i = i + 20;
		if (str[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	if (i == ft_strlen(str))
		return (1);
	return (0);
}
