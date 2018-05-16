/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_newline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:43:34 by romoldov          #+#    #+#             */
/*   Updated: 2018/01/25 18:00:25 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_newline(char const *s)
{
	int		index;

	if (s)
	{
		index = 0;
		while (s[index] != '\0')
		{
			ft_putchar(s[index]);
			index++;
		}
	}
	ft_putchar('\n');
}
