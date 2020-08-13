/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_5_info3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:06:18 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:06:20 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_info3_add(t_info3 *info3a, t_info3 *info3b)
{
	info3a->x_r += info3b->x_r;
	info3a->y_g += info3b->y_g;
	info3a->z_b += info3b->z_b;
}

void	rt_info3_mul(t_info3 *info3a, t_info3 *info3b)
{
	info3a->x_r *= info3b->x_r;
	info3a->y_g *= info3b->y_g;
	info3a->z_b *= info3b->z_b;
}

void	rt_info3_diff(t_info3 *info3a, t_info3 *info3b, t_info3 *diff)
{
	diff->x_r = info3a->x_r - info3b->x_r;
	diff->y_g = info3a->y_g - info3b->y_g;
	diff->z_b = info3a->z_b - info3b->z_b;
}

double	rt_info3_dot(t_info3 *info3a, t_info3 *info3b)
{
	return (info3a->x_r * info3b->x_r
		+ info3a->y_g * info3b->y_g
		+ info3a->z_b * info3b->z_b);
}

void	rt_info3_limit(t_info3 *info3, double limit)
{
	if (info3->x_r < 0.0)
		info3->x_r = 0.0;
	else if (info3->x_r > limit)
		info3->x_r = limit;
	if (info3->y_g < 0.0)
		info3->y_g = 0.0;
	else if (info3->y_g > limit)
		info3->y_g = limit;
	if (info3->z_b < 0.0)
		info3->z_b = 0.0;
	else if (info3->z_b > limit)
		info3->z_b = limit;
}
