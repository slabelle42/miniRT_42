/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:27:45 by slabelle          #+#    #+#             */
/*   Updated: 2020/04/05 16:27:47 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_itoa_ull(unsigned long long n)
{
	unsigned long long	ull_n;
	int					len;
	char				*str;

	ull_n = n;
	len = 2;
	while ((ull_n /= 10))
		len++;
	if (!(str = malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
