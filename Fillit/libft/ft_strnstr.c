/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:29:00 by romoldov          #+#    #+#             */
/*   Updated: 2018/01/18 19:10:20 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	int		i;
	int		j;
	char	*ptr_big;
	char	*ptr_little;

	i = 0;
	j = 0;
	ptr_big = (char *)big;
	ptr_little = (char *)little;
	if (ft_strlen(ptr_little) == 0)
		return (ptr_big);
	while (ptr_big[i] && len-- >= ft_strlen(ptr_little))
	{
		while (ptr_little[j] == ptr_big[i + j])
		{
			if (j == ft_strlen(ptr_little) - 1)
				return (ptr_big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
