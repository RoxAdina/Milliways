/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:56:04 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/17 18:00:32 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		long_nb;

	if (n == -2147483648)
	{
		long_nb = n / 10;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-long_nb, fd);
	}
	if (-2147483648 < n && n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n == -2147483648)
		ft_putchar_fd(n + '8', fd);
	else
		ft_putchar_fd(n + '0', fd);
}
