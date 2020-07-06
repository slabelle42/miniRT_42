/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:44:41 by slabelle          #+#    #+#             */
/*   Updated: 2019/10/12 14:11:41 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_getstr(long n, int len, char *str)
{
	int		sign;

	sign = 1;
	str[len-- - 1] = '\0';
	if (n == 0)
		str[len - 1] = '0';
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	while (n > 0)
	{
		str[len-- - 1] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		str[len - 1] = '-';
	return (str);
}

int		ft_itoa_getlen(long n)
{
	int		len;

	len = 1;
	if (n <= 0)
	{
		len = 2;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	long_n;
	int		len;
	char	*str;

	long_n = n;
	len = ft_itoa_getlen(long_n);
	if (!(str = malloc(sizeof(char) * len)))
		return (NULL);
	return (ft_itoa_getstr(long_n, len, str));
}
