/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:05:45 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/16 14:17:33 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	i;
	size_t	len;

	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		while (i < len)
		{
			s[i] = '\0';
			i++;
		}
	}
}
