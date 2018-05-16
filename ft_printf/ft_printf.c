/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:32:47 by romoldov          #+#    #+#             */
/*   Updated: 2018/03/07 20:28:58 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		argumente;
	int			scrise;

	scrise = 0;
	va_start(argumente, format);
	scrise = parse_string((char *)format, &argumente);
	va_end(argumente);
	return (scrise);
}

int		parse_string(char *format, va_list *args)
{
	int		citite;

	citite = 0;
	while (*format)
	{
		if (format[0] == '%' && format[1] == '\0')
			return (citite);
		if (format[0] == '%')
		{
			format++;
			citite = citite + handle_format(args, &format, citite);
			continue;
		}
		ft_putchar(*format);
		citite++;
		format++;
	}
	return (citite);
}

int		handle_format(va_list *lst, char **format, int n)
{
	int		citite;
	t_flags	f;

	reset_flags(&f);
	parse_flags(format, &f);
	parse_width(format, lst, &f);
	parse_precision(format, lst, &f);
	parse_length(format, &f);
	citite = handle_specifiers(format, lst, &f, n);
	return (citite);
}

int		handle_specifiers(char **format, va_list *lst, t_flags *f, int n)
{
	if (**format == 'd' || **format == 'i')
	{
		(*format)++;
		return (int_handle(f, lst));
	}
	else if (**format == 'u')
	{
		(*format)++;
		return (unsigned_handle(f, lst));
	}
	else if (**format == 'o')
	{
		(*format)++;
		return (octal_handle(f, lst));
	}
	else if (**format == 'x')
	{
		(*format)++;
		return (hex_handle(f, lst, 0));
	}
	return (handle_specifiers2(format, lst, f, n));
}

int		handle_specifiers2(char **format, va_list *lst, t_flags *f, int n)
{
	if (**format == 'X')
	{
		(*format)++;
		return (hex_handle(f, lst, 1));
	}
	else if (**format == 'p')
	{
		(*format)++;
		return (address_handle(f, lst));
	}
	else if (**format == 'D')
	{
		(*format)++;
		f->l = 1;
		return (int_handle(f, lst));
	}
	else if (**format == 'O')
	{
		(*format)++;
		f->l = 1;
		return (octal_handle(f, lst));
	}
	return (handle_specifiers3(format, lst, f, n));
}
