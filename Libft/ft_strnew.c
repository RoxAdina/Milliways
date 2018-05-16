/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:39:06 by romoldov          #+#    #+#             */
/*   Updated: 2018/02/20 17:17:55 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (str = (char *)malloc(sizeof(*str) * (size + 1)) != NULL)
	{
		i = 0;
		if (str)
		{
			while (i <= size)
			{
				str[i] = '\0';
				i++;
			}
			return (str);
		}
	}
	else
		return (NULL);
}
