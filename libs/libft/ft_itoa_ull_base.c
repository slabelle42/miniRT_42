/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:27:36 by slabelle          #+#    #+#             */
/*   Updated: 2020/04/05 17:10:31 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	ft_itoa_ull_base_divide(unsigned long long n,
							int base)
{
	unsigned long long		div_nbr;

	div_nbr = 0;
	while (n)
	{
		n /= base;
		div_nbr++;
	}
	return (div_nbr);
}

static char					*ft_itoa_ull_base_zero(void)
{
	char					*output;

	if (!(output = malloc(sizeof(char) * 2)))
		return (NULL);
	output[0] = '0';
	output[1] = '\0';
	return (output);
}

char						*ft_itoa_ull_base(unsigned long long n, int base)
{
	char					*output;
	char					tab_base[17];
	unsigned long long		div_nbr;
	int						i;

	if (base > 36 || base < 2)
		return (NULL);
	if (n == 0)
		return (ft_itoa_ull_base_zero());
	if (base == 10)
		return (ft_itoa_ull(n));
	ft_strcpy(tab_base, "0123456789abcdef");
	div_nbr = ft_itoa_ull_base_divide(n, base);
	if (!(output = malloc(sizeof(char) * (div_nbr + 1))))
		return (NULL);
	i = 1;
	while (n)
	{
		output[div_nbr - i++] = tab_base[n % base];
		n /= base;
	}
	output[div_nbr] = '\0';
	return (output);
}
