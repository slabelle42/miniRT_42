/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_6_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 20:37:12 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/13 20:37:14 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		rt_image_rotation_x(t_info3 *info3, double alpha)
{
	double	y;
	double	z;

	y = info3->y_g * cos(M_PI * alpha) - info3->z_b * sin(M_PI * alpha);
	z = info3->y_g * sin(M_PI * alpha) + info3->z_b * cos(M_PI * alpha);
	info3->y_g = y;
	info3->z_b = z;
}

void		rt_image_rotation_y(t_info3 *info3, double beta)
{
	double	x;
	double	z;

	x = info3->x_r * cos(M_PI * beta) + info3->z_b * sin(M_PI * beta);
	z = info3->x_r * -sin(M_PI * beta) + info3->z_b * cos(M_PI * beta);
	info3->x_r = x;
	info3->z_b = z;
}

void		rt_image_rotation_z(t_info3 *info3, double gamma)
{
	double	x;
	double	y;

	x = info3->x_r * cos(M_PI * gamma) - info3->y_g * sin(M_PI * gamma);
	y = info3->x_r * sin(M_PI * gamma) + info3->y_g * cos(M_PI * gamma);
	info3->x_r = x;
	info3->y_g = y;
}

t_info3		*rt_image_rotation_xyz(double x, double y, double z, t_info3 *vec)
{
	t_info3	*rot;

	rot = rt_init_info3();
	rot->x_r = x;
	rot->y_g = y;
	rot->z_b = z;
	rt_image_rotation_x(rot, vec->x_r);
	rt_image_rotation_y(rot, vec->y_g);
	rt_image_rotation_z(rot, vec->z_b);
	return (rot);
}
