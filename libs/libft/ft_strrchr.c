/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:07:43 by slabelle          #+#    #+#             */
/*   Updated: 2019/10/12 16:07:45 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*char_str;
	char	char_c;

	char_str = (char *)str;
	char_c = (char)c;
	while (*char_str)
		char_str++;
	while (char_str >= str)
	{
		if (*char_str == char_c)
			return (char_str);
		char_str--;
	}
	return (NULL);
}
