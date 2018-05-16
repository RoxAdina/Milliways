/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:44:12 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/12 18:00:39 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(*s2) * (len + 1));
	if (s2)
	{
		ft_memcpy(s2, s1, len);
		s2[len] = '\0';
		return (s2);
	}
	else
		return (NULL);
}
