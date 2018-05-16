/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makegrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:04:25 by romoldov          #+#    #+#             */
/*   Updated: 2018/01/18 18:04:43 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_makegrid(int i)
{
	int		j;
	char	*str;

	str = (char*)malloc(sizeof(char) * (i * (i + 1) + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (j < i * (i + 1) - 1)
	{
		if ((j + 1) % (i + 1) != 0)
			str[j] = '.';
		else
			str[j] = '\n';
		j++;
	}
	str[j] = '\0';
	return (str);
}
