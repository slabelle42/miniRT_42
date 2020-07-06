/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:45:14 by slabelle          #+#    #+#             */
/*   Updated: 2019/11/11 16:41:13 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*char_dst;
	char	*char_src;
	size_t	i;

	if (dst != src && len)
	{
		char_dst = (char *)dst;
		char_src = (char *)src;
		if (dst < src)
		{
			i = -1;
			while (++i < len)
				char_dst[i] = char_src[i];
		}
		else
		{
			while (len-- > 0)
				char_dst[len] = char_src[len];
		}
	}
	return (dst);
}
