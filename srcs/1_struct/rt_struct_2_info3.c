/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct_2_info3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:04:46 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:04:48 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_info3		*rt_init_info3(void)
{
	t_info3	*info3;

	if (!(info3 = ft_memalloc(sizeof(t_info3))))
		rt_exit(ERR_MALLOC);
	info3->x_r = 0.0;
	info3->y_g = 0.0;
	info3->z_b = 0.0;
	return (info3);
}

void		rt_copy_info3(t_info3 *info3, t_info3 *cpy)
{
	cpy->x_r = info3->x_r;
	cpy->y_g = info3->y_g;
	cpy->z_b = info3->z_b;
}

void		rt_fill_info3(t_info3 *info3, double a, double b, double c)
{
	info3->x_r = a;
	info3->y_g = b;
	info3->z_b = c;
}
