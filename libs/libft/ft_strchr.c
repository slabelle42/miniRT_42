/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:49:03 by slabelle          #+#    #+#             */
/*   Updated: 2019/10/12 15:49:05 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*char_str;
	char	char_c;

	char_str = (char *)str;
	char_c = (char)c;
	while (*char_str)
	{
		if (*char_str == char_c)
			return (char_str);
		char_str++;
	}
	if (*char_str == char_c)
		return (char_str);
	return (NULL);
}
