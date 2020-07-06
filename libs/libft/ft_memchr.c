/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:07:13 by slabelle          #+#    #+#             */
/*   Updated: 2019/10/12 15:07:19 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	void			*void_str;
	unsigned char	*uchar_str;
	unsigned char	uchar_c;
	size_t			i;

	void_str = (void *)str;
	uchar_str = (unsigned char *)str;
	uchar_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		if (uchar_str[i] == uchar_c)
			return (void_str + i);
		i++;
	}
	return (NULL);
}
