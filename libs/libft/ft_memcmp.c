/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:42:02 by slabelle          #+#    #+#             */
/*   Updated: 2019/11/11 17:03:34 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*uchar_s1;
	unsigned char	*uchar_s2;

	if (s1 != s2 && len)
	{
		uchar_s1 = (unsigned char *)s1;
		uchar_s2 = (unsigned char *)s2;
		while (len--)
		{
			if (*uchar_s1 != *uchar_s2)
				return (*uchar_s1 - *uchar_s2);
			if (len)
			{
				uchar_s1++;
				uchar_s2++;
			}
		}
	}
	return (0);
}
