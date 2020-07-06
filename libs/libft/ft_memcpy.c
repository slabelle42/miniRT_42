/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:43:52 by slabelle          #+#    #+#             */
/*   Updated: 2019/11/11 16:29:07 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*char_dst;
	char	*char_src;

	if (dst != src && len)
	{
		char_dst = (char *)dst;
		char_src = (char *)src;
		while (len--)
			char_dst[len] = char_src[len];
	}
	return (dst);
}
