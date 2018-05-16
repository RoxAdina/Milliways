/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:30:18 by romoldov          #+#    #+#             */
/*   Updated: 2018/02/20 17:31:10 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*read_file(const int fd)
{
	int		read_bytes;
	char	buff[BUFF_SIZE + 1];
	char	*file;
	char	*leak;

	if (!(file = (char *)malloc(sizeof(char))))
		return (NULL);
	file[0] = '\0';
	while ((read_bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (read_bytes == -1)
			return (NULL);
		leak = file;
		buff[read_bytes] = '\0';
		if (!(file = ft_strjoin(file, buff)))
			return (NULL);
		free(leak);
	}
	return (file);
}

t_fdlist	*write_fd(t_fdlist **fd_list, const int fd)
{
	t_fdlist	*temp_fd_2;

	temp_fd_2 = *fd_list;
	while (temp_fd_2)
	{
		if (temp_fd_2->fd == fd)
			return (temp_fd_2);
		temp_fd_2 = temp_fd_2->next;
	}
	if (!(temp_fd_2 = (t_fdlist*)malloc(sizeof(t_fdlist))))
		return (NULL);
	temp_fd_2->fd = fd;
	if (!(temp_fd_2->file = read_file(fd)))
		return (NULL);
	temp_fd_2->i = 0;
	temp_fd_2->check_final = 222;
	temp_fd_2->next = *fd_list;
	*fd_list = temp_fd_2;
	temp_fd_2 = *fd_list;
	if (*(temp_fd_2->file) == '\0')
		temp_fd_2->check_final = 442;
	return (temp_fd_2);
}

int			extract_line(t_fdlist *temp_fd_3, char **line)
{
	int j;

	j = temp_fd_3->i;
	while (temp_fd_3->file[temp_fd_3->i] != '\n' &&
			temp_fd_3->file[temp_fd_3->i] != '\0')
		(temp_fd_3->i)++;
	if (!(*line = (char*)malloc(sizeof(char) * (temp_fd_3->i - j + 1))))
		return (9001);
	ft_strncpy(*line, temp_fd_3->file + j, (size_t)(temp_fd_3->i - j));
	(*line)[temp_fd_3->i - j] = '\0';
	if (temp_fd_3->file[temp_fd_3->i] == '\n')
		(temp_fd_3->i)++;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_fdlist		*fd_list;
	t_fdlist			*temp_fd;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	temp_fd = write_fd(&fd_list, fd);
	if (temp_fd == NULL)
		return (-1);
	if (temp_fd->check_final == 442)
		return (0);
	if (extract_line(temp_fd, line) == 9001)
		return (-1);
	if (temp_fd->file[temp_fd->i] == '\0')
	{
		temp_fd->check_final = 442;
		free(temp_fd->file);
		return (1);
	}
	return (1);
}
