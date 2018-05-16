/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_related.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:28:47 by romoldov          #+#    #+#             */
/*   Updated: 2018/03/07 17:38:28 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwide(wchar_t c)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}

int		ft_charlen(wchar_t c)
{
	int		i;

	i = 0;
	if (c <= 0x7F)
		i++;
	else if (c <= 0x7FF)
		i = i + 2;
	else if (c <= 0xFFFF)
		i = i + 3;
	else if (c <= 0x10FFFF)
		i = i + 4;
	return (i);
}

int		widechar_handle(va_list *lst, t_flags *f)
{
	wchar_t		c;
	int			len;

	c = va_arg(*lst, wint_t);
	len = f->width - ft_charlen(c);
	if (len > 0)
	{
		if (f->minus)
		{
			ft_putwide(c);
			print_padd(len, ' ');
		}
		else
		{
			print_padd(len, (f->zero) ? '0' : ' ');
			ft_putwide(c);
		}
		return (f->width);
	}
	ft_putwide(c);
	return (ft_charlen(c));
}

int		ft_widestrlen(wchar_t *wstr)
{
	int		i;

	i = 0;
	while (*wstr != '\0')
	{
		i = i + ft_charlen(*wstr);
		wstr++;
	}
	return (i);
}

int		ft_putwidestr(wchar_t *wstr, int how_much)
{
	int		i;

	i = 0;
	while (*wstr)
	{
		how_much = how_much - ft_charlen(*wstr);
		if (how_much < 0)
			return (i);
		ft_putwide(*wstr);
		i = i + ft_charlen(*wstr);
		wstr++;
	}
	return (i);
}
