/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:37:14 by slabelle          #+#    #+#             */
/*   Updated: 2020/02/10 15:51:02 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		free_and_null(char **to_free)
{
	if (to_free && *to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

static char		*join_buffer(char *save, char *buffer)
{
	size_t			len_buffer;
	size_t			len_save;
	size_t			len;
	char			*join;

	len_buffer = ft_strlen(buffer);
	len_save = 0;
	if (save)
		len_save = ft_strlen(save);
	len = len_buffer + len_save;
	if (!(join = ft_memalloc(len + 1)))
		return (NULL);
	if (save)
	{
		ft_strlcpy(join, save, (len_save + 1));
		free_and_null(&save);
	}
	ft_strlcpy((join + len_save), buffer, (len_buffer + 1));
	return (join);
}

static int		line_saved(char **save, char **line)
{
	char			*found;
	size_t			end;
	size_t			len;

	found = NULL;
	if ((found = ft_strchr(*save, '\n')))
	{
		end = found - *save;
		len = ft_strlen(found);
		*line = ft_substr(*save, 0, end);
		ft_strlcpy(*save, (found + 1), (len + 1));
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*save[MAX_FD];
	int				nbytes;

	if (fd < 0 || fd > MAX_FD || !line || BUFFER_SIZE < 1
		|| read(fd, buffer, 0) < 0)
		return (-1);
	if (save[fd] && line_saved(&save[fd], line))
		return (1);
	while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nbytes] = '\0';
		if (!(save[fd] = join_buffer(save[fd], buffer)))
			return (-1);
		if (line_saved(&save[fd], line))
			return (1);
	}
	if (save[fd] && *save[fd])
		*line = ft_strdup(save[fd]);
	free_and_null(&save[fd]);
	return (nbytes);
}
