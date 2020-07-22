/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:39:06 by slabelle          #+#    #+#             */
/*   Updated: 2020/02/01 18:39:10 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(char const *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!(sub = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	if (!(start > gnl_strlen(s)))
	{
		while (s[start] && i < len)
			sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = gnl_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

char	*gnl_strdup(const char *src)
{
	size_t	dst_len;
	char	*dst;
	int		i;

	dst_len = gnl_strlen(src) + 1;
	if (!(dst = malloc(sizeof(char) * dst_len)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
