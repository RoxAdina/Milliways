/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:46:45 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/16 16:03:21 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int				i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (s1 && s2)
	{
		i = 0;
		ptr1 = (unsigned char *)s1;
		ptr2 = (unsigned char *)s2;
		while (ptr1[i] == ptr2[i] && ptr1[i] && ptr2[i])
			i++;
		if (ptr1[i] == '\0' && ptr2[i] == '\0')
			return (1);
	}
	return (0);
}
