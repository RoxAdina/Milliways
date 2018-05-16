/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:33:12 by romoldov          #+#    #+#             */
/*   Updated: 2018/03/09 19:05:45 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include <unistd.h>

typedef long long int			t_s64;
typedef unsigned long long int	t_u64;

typedef	struct					s_flags
{
	int		minus;
	int		plus;
	int		space;
	int		diez;
	int		zero;

	int		width;

	int		precision;
	int		dot;

	int		hh;
	int		h;
	int		l;
	int		ll;
	int		j;
	int		z;
	int		citite;
}								t_flags;

int								ft_printf(const char *format, ...);
int								parse_string(char *format, va_list *args);
int								handle_format(va_list *lst,
								char **format, int n);
int								handle_specifiers(char **format,
								va_list *lst, t_flags *f, int n);
int								handle_specifiers2(char **format,
								va_list *lst, t_flags *f, int n);
int								handle_specifiers3(char **format,
								va_list *lst, t_flags *f, int n);
int								handle_specifiers4(char **format,
								va_list *lst, t_flags *f, int n);
int								undefined_handle(t_flags *f, char c);
int								int_handle(t_flags *f, va_list *lst);
int								n_handle(va_list *lst, t_flags *f, int n);
int								unsigned_handle(t_flags *f, va_list *lst);
int								octal_handle(t_flags *f, va_list *lst);
int								hex_handle(t_flags *f,
								va_list *lst, int case01);
int								address_handle(t_flags *f, va_list *lst);
int								percent_handle(t_flags *f);
int								char_handle(t_flags *f, va_list *lst);
int								string_handle(t_flags *f, va_list *lst);
t_s64							handle_signed_length(va_list *lst,
								t_flags *f);
t_u64							handle_unsigned_length(va_list *lst,
								t_flags *f);
void							parse_flags(char **format, t_flags *f);
void							parse_length(char **format, t_flags *f);
void							parse_precision(char **format,
								va_list *lst, t_flags *f);
void							parse_width(char **format,
								va_list *lst, t_flags *f);
void							reset_flags(t_flags *f);
void							itoa_isnegative_long(t_s64 *n, int *negative);
char							*ft_itoa_long(t_s64 n);
int								calc_precision(char *s, t_flags *f);
void							print_padd(int n, char c);
void							print_precision(char *s, t_flags *f);
int								apply_all(char *s, t_flags *f, char *prefix);
void							padd_front(char *s, t_flags *f,
								char *prefix, int len);
char							*ft_itoa_ulong(t_u64 n, int base, int case01);
void							ft_putwide(wchar_t c);
int								ft_charlen(wchar_t c);
int								widechar_handle(va_list *lst, t_flags *f);
int								ft_widestrlen(wchar_t *wstr);
int								ft_putwidestr(wchar_t *wstr, int how_much);
int								wide_precision_len(wchar_t *wstr, t_flags *f);
int								widestr_precision(wchar_t *wstr, t_flags *f);
int								widestr_width(wchar_t *wstr, t_flags *f);
int								widestr_handle(va_list *lst, t_flags *f);
int								binary_handle(va_list *lst, t_flags *f);

#endif
