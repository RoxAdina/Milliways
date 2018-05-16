/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:21:18 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/17 18:28:25 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	while (little[size] != '\0')
		size++;
	if (size == 0)
		return ((char *)big);
	while (big[i])
	{
		while (little[j] == big[i + j])
		{
			if (j == size - 1)
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
