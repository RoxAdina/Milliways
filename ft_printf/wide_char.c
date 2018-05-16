/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:32:17 by romoldov          #+#    #+#             */
/*   Updated: 2018/03/07 17:43:58 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wide_precision_len(wchar_t *wstr, t_flags *f)
{
	int		i;
	int		prec;

	i = 0;
	prec = f->precision;
	if (f->dot == 0)
		return (ft_widestrlen(wstr));
	while (*wstr)
	{
		prec = prec - ft_charlen(*wstr);
		if (prec < 0)
			return (i);
		i = i + ft_charlen(*wstr);
		wstr++;
	}
	return (i);
}

int		widestr_precision(wchar_t *wstr, t_flags *f)
{
	int		len;
	int		i;

	i = 0;
	len = f->precision - ft_widestrlen(wstr);
	if (len < 0 && f->dot)
		i = ft_putwidestr(wstr, f->precision);
	else
		i = ft_putwidestr(wstr, ft_widestrlen(wstr));
	return (i);
}

int		widestr_width(wchar_t *wstr, t_flags *f)
{
	int		len;

	len = f->width - wide_precision_len(wstr, f);
	if (len > 0)
	{
		if (f->minus)
		{
			widestr_precision(wstr, f);
			print_padd(len, ' ');
		}
		else
		{
			print_padd(len, (f->zero) ? '0' : ' ');
			widestr_precision(wstr, f);
		}
		return (f->width);
	}
	return (widestr_precision(wstr, f));
}

int		widestr_handle(va_list *lst, t_flags *f)
{
	wchar_t		*s;
	int			ret;

	s = va_arg(*lst, wchar_t *);
	if (s == NULL)
		s = L"(null)";
	ret = widestr_width(s, f);
	return (ret);
}
