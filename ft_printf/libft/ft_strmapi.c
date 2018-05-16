/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:39:59 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/17 18:39:26 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	size_t			len;
	unsigned int	i;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		s2 = (char *)malloc(sizeof(*s2) * (len + 1));
		if (s2)
		{
			while (s[i])
			{
				s2[i] = f(i, s[i]);
				i++;
			}
			s2[i] = '\0';
			return (s2);
		}
	}
	return (NULL);
}
