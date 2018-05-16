/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:34:37 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/14 18:59:44 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
