/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:45:59 by romoldov          #+#    #+#             */
/*   Updated: 2018/03/09 19:05:10 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string_handle(t_flags *f, va_list *lst)
{
	int		ret;
	char	*s;
	int		len;
	int		null;

	null = 0;
	if (f->l)
		return (widestr_handle(lst, f));
	s = va_arg(*lst, char *);
	if (s == NULL)
	{
		s = "(null)";
		null = 1;
	}
	if (!(s = ft_strdup(s)))
		exit(1);
	len = f->precision - ft_strlen(s);
	if (len < 0 && f->dot)
		s[f->precision] = '\0';
	f->dot = 0;
	f->precision = 0;
	ret = apply_all(s, f, "");
	if (null == 0)
		free(s);
	return (ret);
}

int		undefined_handle(t_flags *f, char c)
{
	if (f->minus)
	{
		ft_putchar(c);
		print_padd(f->width - 1, ' ');
	}
	else
	{
		print_padd(f->width - 1, (f->zero) ? '0' : ' ');
		ft_putchar(c);
	}
	return ((f->width > 0) ? f->width : 1);
}

int		int_handle(t_flags *f, va_list *lst)
{
	int		ret;
	char	*s;
	t_s64	n;

	n = handle_signed_length(lst, f);
	s = ft_itoa_long(n);
	if (n == 0 && f->dot == 1 && f->precision == 0)
		return (apply_all("", f, ""));
	if (f->precision > 0)
		f->zero = 0;
	if (n < 0)
		ret = apply_all(s + 1, f, "-");
	else if (f->plus)
		ret = apply_all(s, f, "+");
	else if (f->space)
		ret = apply_all(s, f, " ");
	else
		ret = apply_all(s, f, "");
	free(s);
	return (ret);
}

int		unsigned_handle(t_flags *f, va_list *lst)
{
	int		ret;
	char	*s;
	t_u64	n;

	n = handle_unsigned_length(lst, f);
	s = ft_itoa_ulong(n, 10, 0);
	if (n == 0 && f->dot == 1 && f->precision == 0)
		return (apply_all("", f, ""));
	if (f->dot)
		f->zero = 0;
	ret = apply_all(s, f, "");
	free(s);
	return (ret);
}

int		octal_handle(t_flags *f, va_list *lst)
{
	int		ret;
	char	*s;
	t_u64	n;

	n = handle_unsigned_length(lst, f);
	s = ft_itoa_ulong(n, 8, 0);
	if (n == 0 && f->dot && f->precision == 0 && !f->diez)
		return (apply_all("", f, ""));
	if (f->dot && f->precision > 0)
	{
		f->diez = 0;
		f->zero = 0;
	}
	if (f->diez && n != 0)
		ret = apply_all(s, f, "0");
	else
		ret = apply_all(s, f, "");
	free(s);
	return (ret);
}
