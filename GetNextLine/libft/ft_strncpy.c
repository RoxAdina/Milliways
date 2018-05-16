/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:08:25 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/12 19:02:53 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen((char*)src);
	while (i < n)
	{
		if (i > len_src)
		{
			dst[i] = '\0';
		}
		else
			dst[i] = src[i];
		i++;
	}
	return (dst);
}
