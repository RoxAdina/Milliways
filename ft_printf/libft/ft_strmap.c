/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:56:23 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/17 18:47:15 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	size_t	len;
	size_t	i;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		s2 = (char *)malloc(sizeof(*s2) * (len + 1));
		if (s2)
		{
			while (s[i])
			{
				s2[i] = f(s[i]);
				i++;
			}
			s2[i] = '\0';
			return (s2);
		}
	}
	return (NULL);
}
