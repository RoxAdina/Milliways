/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_longs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:45:08 by romoldov          #+#    #+#             */
/*   Updated: 2018/03/08 15:45:19 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	itoa_isnegative_long(t_s64 *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char	*ft_itoa_long(t_s64 n)
{
	t_s64	temp;
	int		len;
	int		negative;
	char	*str;

	if (n == (-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
	temp = n;
	len = 2;
	negative = 0;
	itoa_isnegative_long(&n, &negative);
	while (temp /= 10)
		len++;
	len += negative;
	if ((str = (char *)malloc(sizeof(*str) * len)) == NULL)
		exit(1);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_ulong(t_u64 n, int base, int case01)
{
	t_u64	temp;
	int		len;
	char	*str;
	int		i;

	temp = n;
	len = 2;
	while (temp /= base)
		len++;
	if ((str = (char *)malloc(sizeof(*str) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		i = n % base;
		if (i > 9)
			str[len] = ((case01 == 0) ? ((39 + i) + '0') : ((7 + i) + '0'));
		else
			str[len] = n % base + '0';
		n = n / base;
	}
	return (str);
}
