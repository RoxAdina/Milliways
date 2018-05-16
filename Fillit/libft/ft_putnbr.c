/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:36:23 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/17 17:43:19 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		long_nb;

	if (n == -2147483648)
	{
		long_nb = n / 10;
		ft_putchar('-');
		ft_putnbr(-long_nb);
	}
	if (-2147483648 < n && n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n == -2147483648)
		ft_putchar(n + '8');
	else
		ft_putchar(n + '0');
}
