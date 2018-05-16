/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minsquare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:05:14 by romoldov          #+#    #+#             */
/*   Updated: 2018/01/18 18:05:28 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_minsquare(int nb_of_tetros)
{
	int		i;
	int		nbr;

	nbr = nb_of_tetros;
	if (nb_of_tetros == 1)
		return (2);
	i = 2;
	nbr = nbr * 4;
	while (i * i < nbr)
		i++;
	return (i);
}
