/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errormsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:02:54 by romoldov          #+#    #+#             */
/*   Updated: 2018/01/26 16:37:08 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_errormsg(int msg)
{
	if (msg == 1)
		ft_putstr_fd("ERROR: Could not open file.\n", 2);
	if (msg == 2)
		ft_putstr_fd("ERROR: The file is too large.\n", 2);
	if (msg == 3)
		ft_putstr_fd("usage: ./fillit [input_file]\n", 2);
}
