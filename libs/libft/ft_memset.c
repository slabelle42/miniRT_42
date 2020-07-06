/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:46:19 by slabelle          #+#    #+#             */
/*   Updated: 2019/10/12 15:46:24 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*uchar_str;
	unsigned char	uchar_c;

	uchar_str = (unsigned char *)str;
	uchar_c = (unsigned char)c;
	while (len--)
		uchar_str[len] = uchar_c;
	return (str);
}
