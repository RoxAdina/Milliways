/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrotogrid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:07:50 by romoldov          #+#    #+#             */
/*   Updated: 2018/01/18 18:08:04 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	**ft_tetrotogrid(int **t, int nb_of_tetros, int width)
{
	int		i;
	int		id;

	id = 0;
	i = 0;
	while (id < nb_of_tetros)
	{
		i = 0;
		while (i < 4)
		{
			t[id][i] = t[id][i] + (t[id][i] / width);
			i++;
		}
		id++;
	}
	return (t);
}
