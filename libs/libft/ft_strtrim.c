/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:08:38 by slabelle          #+#    #+#             */
/*   Updated: 2019/11/01 17:32:10 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strtrim_getlen(char const *s1, char const *set)
{
	size_t			len;
	int				next;
	int				i;

	len = ft_strlen(s1);
	next = 1;
	while (s1[len - 1] && next == 1)
	{
		next = 0;
		i = 0;
		while (set[i] && next == 0)
		{
			if (set[i] == s1[len - 1])
			{
				next = 1;
				len--;
			}
			i++;
		}
	}
	return (len);
}

unsigned int	ft_strtrim_getstart(char const *s1, char const *set)
{
	unsigned int	start;
	int				next;
	int				i;

	start = 0;
	next = 1;
	while (s1[start] && next == 1)
	{
		next = 0;
		i = 0;
		while (set[i] && next == 0)
		{
			if (set[i] == s1[start])
			{
				next = 1;
				start++;
			}
			i++;
		}
	}
	return (start);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	char			*empty;
	size_t			len;

	start = ft_strtrim_getstart(s1, set);
	if (!(s1[start]))
	{
		if (!(empty = malloc(sizeof(char) * 1)))
			return (NULL);
		empty[0] = '\0';
		return (empty);
	}
	len = ft_strtrim_getlen(s1, set) - start;
	return (ft_substr(s1, start, len));
}
