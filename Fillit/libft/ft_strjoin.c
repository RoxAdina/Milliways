/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:42:45 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/17 18:06:10 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 && s2)
	{
		s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (s3)
		{
			ft_strcat(s3, s1);
			ft_strcat(s3, s2);
			return (s3);
		}
	}
	return (NULL);
}
