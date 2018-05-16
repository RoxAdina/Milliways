/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:20:37 by romoldov          #+#    #+#             */
/*   Updated: 2018/03/07 19:22:40 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hex_handle(t_flags *f, va_list *lst, int case01)
{
	int		ret;
	char	*s;
	t_u64	n;

	n = handle_unsigned_length(lst, f);
	s = ft_itoa_ulong(n, 16, case01);
	if (n == 0 && f->dot && f->precision == 0)
		return (apply_all("", f, ""));
	if (f->dot && f->precision > 0)
		f->zero = 0;
	if (f->diez && n != 0)
		ret = apply_all(s, f, (case01 == 0) ? "0x" : "0X");
	else
		ret = apply_all(s, f, "");
	free(s);
	return (ret);
}

int		address_handle(t_flags *f, va_list *lst)
{
	t_u64		n;
	void		*p;
	int			ret;
	char		*s;

	p = va_arg(*lst, void *);
	if (p == NULL && f->dot && f->precision == 0)
		return (apply_all("", f, "0x"));
	n = (t_u64)p;
	s = ft_itoa_ulong(n, 16, 0);
	ret = apply_all(s, f, "0x");
	free(s);
	return (ret);
}

int		calc_precision(char *s, t_flags *f)
{
	int		len;

	len = f->precision - ft_strlen(s);
	if (len > 0)
		return (f->precision);
	else
		return (ft_strlen(s));
}

void	print_padd(int n, char c)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
}

void	print_precision(char *s, t_flags *f)
{
	int		len;

	len = f->precision - ft_strlen(s);
	if (len > 0)
	{
		print_padd(len, '0');
		ft_putstr(s);
	}
	else
		ft_putstr(s);
}
