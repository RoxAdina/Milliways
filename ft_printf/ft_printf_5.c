/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:10:52 by romoldov          #+#    #+#             */
/*   Updated: 2018/03/07 19:22:24 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_all(char *s, t_flags *f, char *prefix)
{
	int		len;

	len = f->width - calc_precision(s, f) - ft_strlen(prefix);
	if (len > 0)
	{
		if (f->minus)
		{
			ft_putstr(prefix);
			print_precision(s, f);
			print_padd(len, ' ');
		}
		else
			padd_front(s, f, prefix, len);
		return (f->width);
	}
	ft_putstr(prefix);
	print_precision(s, f);
	return (ft_strlen(prefix) + calc_precision(s, f));
}

void	padd_front(char *s, t_flags *f, char *prefix, int len)
{
	if (f->zero == 1)
	{
		ft_putstr(prefix);
		print_padd(len, '0');
		print_precision(s, f);
	}
	else
	{
		print_padd(len, ' ');
		ft_putstr(prefix);
		print_precision(s, f);
	}
}

t_s64	handle_signed_length(va_list *lst, t_flags *f)
{
	t_s64		ret;

	if (f->l)
		ret = va_arg(*lst, long);
	else if (f->ll)
		ret = va_arg(*lst, t_s64);
	else if (f->h)
		ret = (short)va_arg(*lst, int);
	else if (f->hh)
		ret = (char)va_arg(*lst, int);
	else if (f->j)
		ret = (intmax_t)va_arg(*lst, intmax_t);
	else if (f->z)
		ret = (size_t)va_arg(*lst, size_t);
	else
		ret = va_arg(*lst, int);
	return (ret);
}

t_u64	handle_unsigned_length(va_list *lst, t_flags *f)
{
	t_u64		ret;

	if (f->l)
		ret = va_arg(*lst, unsigned long);
	else if (f->ll)
		ret = va_arg(*lst, t_u64);
	else if (f->h)
		ret = (unsigned short)va_arg(*lst, unsigned int);
	else if (f->hh)
		ret = (unsigned char)va_arg(*lst, unsigned int);
	else if (f->j)
		ret = (uintmax_t)va_arg(*lst, uintmax_t);
	else if (f->z)
		ret = (size_t)va_arg(*lst, size_t);
	else
		ret = va_arg(*lst, unsigned int);
	return (ret);
}

void	parse_flags(char **format, t_flags *f)
{
	int		parse;

	parse = 1;
	while (parse)
	{
		if (**format == '-')
			f->minus = 1;
		else if (**format == '+')
			f->plus = 1;
		else if (**format == '0')
			f->zero = 1;
		else if (**format == ' ')
			f->space = 1;
		else if (**format == '#')
			f->diez = 1;
		else
			parse = 0;
		if (parse != 0)
			(*format)++;
	}
}
