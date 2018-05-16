/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:33:20 by romoldov          #+#    #+#             */
/*   Updated: 2018/02/20 18:00:41 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 222
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <unistd.h>

typedef struct			s_fdlist
{
	int					fd;
	char				*file;
	int					i;
	struct s_fdlist		*next;
	int					check_final;
}						t_fdlist;

int						get_next_line(const int fd, char **line);
#endif
