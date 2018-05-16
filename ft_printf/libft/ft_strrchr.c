/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:27:43 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/14 19:50:07 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*ptr;

	ptr = (char *)s;
	len = ft_strlen(s);
	if (c == '\0')
		return (ptr + len);
	while (len >= 1)
	{
		if (ptr[len - 1] == (char)c)
			return (ptr + len - 1);
		len--;
	}
	return (NULL);
}
