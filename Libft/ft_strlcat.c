/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:33:50 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/18 16:46:11 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	char	*s;
	char	*reader;

	s = (char *)ft_memchr(dst, '\0', size);
	if (s == NULL)
		return (size + ft_strlen(src));
	reader = (char *)src;
	len = (size_t)(s - dst) + ft_strlen(reader);
	while ((size_t)(s - dst) < size - 1 && *reader != '\0')
	{
		*s = *reader;
		s++;
		reader++;
	}
	*s = '\0';
	return (len);
}
