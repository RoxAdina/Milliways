/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:27:10 by romoldov          #+#    #+#             */
/*   Updated: 2018/03/09 19:04:03 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_specifiers3(char **format, va_list *lst, t_flags *f, int n)
{
	if (**format == 'U')
	{
		(*format)++;
		f->l = 1;
		return (unsigned_handle(f, lst));
	}
	else if (**format == '%')
	{
		(*format)++;
		return (percent_handle(f));
	}
	else if (**format == 'c')
	{
		(*format)++;
		return (char_handle(f, lst));
	}
	else if (**format == 's')
	{
		(*format)++;
		return (string_handle(f, lst));
	}
	return (handle_specifiers4(format, lst, f, n));
}

int		handle_specifiers4(char **format, va_list *lst, t_flags *f, int n)
{
	if (**format == 'S')
	{
		(*format)++;
		return (widestr_handle(lst, f));
	}
	else if (**format == 'C')
	{
		(*format)++;
		return (widechar_handle(lst, f));
	}
	else if (**format == 'n')
	{
		(*format)++;
		return (n_handle(lst, f, n));
	}
	else if (**format == 'b')
	{
		(*format)++;
		return (binary_handle(lst, f));
	}
	else
	{
		(*format)++;
		return (undefined_handle(f, *((*format) - 1)));
	}
}

int		n_handle(va_list *lst, t_flags *f, int n)
{
	t_s64		*p;

	if (f->hh)
		p = (t_s64 *)va_arg(*lst, char *);
	else if (f->h)
		p = (t_s64 *)va_arg(*lst, short int *);
	else if (f->l)
		p = (t_s64 *)va_arg(*lst, long int *);
	else if (f->ll)
		p = va_arg(*lst, long long int *);
	else if (f->j)
		p = (t_s64 *)va_arg(*lst, intmax_t *);
	else if (f->z)
		p = (t_s64 *)va_arg(*lst, size_t *);
	else
		p = (t_s64 *)va_arg(*lst, int *);
	*p = n;
	return (0);
}

int		percent_handle(t_flags *f)
{
	int		ret;

	f->precision = 0;
	f->dot = 0;
	ret = apply_all("%", f, "");
	return (ret);
}

int		char_handle(t_flags *f, va_list *lst)
{
	char	c;

	if (f->l)
		return (widechar_handle(lst, f));
	c = (char)va_arg(*lst, int);
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
