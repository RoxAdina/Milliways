/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:53:41 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/12 16:35:06 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_dst;
	char	*ptr_src;

	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (ptr_dst <= ptr_src)
		ft_memcpy(ptr_dst, ptr_src, len);
	else
	{
		while (len--)
			ptr_dst[len] = ptr_src[len];
	}
	return (ptr_dst);
}
