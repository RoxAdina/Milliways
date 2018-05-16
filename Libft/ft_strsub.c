/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:12:12 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/16 16:28:07 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	if (s)
	{
		i = 0;
		j = start;
		sub = ft_strnew(len);
		if (sub)
		{
			while (j < (start + len))
			{
				sub[i] = s[j];
				i++;
				j++;
			}
			sub[i] = '\0';
			return (sub);
		}
	}
	return (NULL);
}
