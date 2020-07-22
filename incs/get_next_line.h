/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:38:45 by slabelle          #+#    #+#             */
/*   Updated: 2020/02/01 18:38:50 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define MAX_FD 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*gnl_strchr(char const *s, int c);
size_t	gnl_strlen(const char *str);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
char	*gnl_strdup(const char *src);

#endif
