/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:46:26 by slabelle          #+#    #+#             */
/*   Updated: 2019/10/12 14:46:30 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*uchar_dst;
	unsigned char	*uchar_src;
	unsigned char	uchar_c;
	size_t			i;

	uchar_dst = (unsigned char *)dst;
	uchar_src = (unsigned char *)src;
	uchar_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		uchar_dst[i] = uchar_src[i];
		if (uchar_src[i] == uchar_c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
