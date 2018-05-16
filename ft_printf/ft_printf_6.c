/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:56:20 by romoldov          #+#    #+#             */
/*   Updated: 2018/03/09 16:45:20 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_length(char **format, t_flags *f)
{
	if (**format == 'h' && (*format)[1] == 'h')
		f->hh = 1;
	else if (**format == 'l' && (*format)[1] == 'l')
		f->ll = 1;
	else if (**format == 'h')
		f->h = 1;
	else if (**format == 'l')
		f->l = 1;
	else if (**format == 'j')
		f->j = 1;
	else if (**format == 'z')
		f->z = 1;
	if (f->h || f->l || f->j || f->z)
		(*format)++;
	else if (f->hh || f->ll)
		(*format) = (*format) + 2;
}

void	parse_precision(char **format, va_list *lst, t_flags *f)
{
	if (**format == '.')
	{
		(*format)++;
		f->dot = 1;
		if (**format == '*')
		{
			f->precision = va_arg(*lst, int);
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			f->precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
	}
}

void	parse_width(char **format, va_list *lst, t_flags *f)
{
	int		parse;

	parse = 1;
	while (parse)
	{
		if (ft_isdigit(**format))
		{
			f->width = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (**format == '*')
		{
			(*format)++;
			f->width = va_arg(*lst, int);
			if (f->width < 0)
			{
				f->minus = 1;
				f->width = f->width * -1;
			}
		}
		else
			parse = 0;
	}
}

void	reset_flags(t_flags *f)
{
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->diez = 0;
	f->zero = 0;
	f->width = 0;
	f->precision = 0;
	f->dot = 0;
	f->hh = 0;
	f->h = 0;
	f->l = 0;
	f->ll = 0;
	f->j = 0;
	f->z = 0;
}

int		binary_handle(va_list *lst, t_flags *f)
{
	int		ret;
	char	*s;
	t_u64	n;

	n = handle_unsigned_length(lst, f);
	s = ft_itoa_ulong(n, 2, 0);
	if (n == 0 && f->dot == 1 && f->precision == 0)
		return (apply_all("", f, ""));
	if (f->dot)
		f->zero = 0;
	ret = apply_all(s, f, "");
	free(s);
	return (ret);
}
