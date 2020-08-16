/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_7_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:05:51 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:05:52 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		rt_image_adjustray(t_rt *rt, t_scn *scn, t_cam *cam, t_ray *ray)
{
	t_info3	*dir;
	t_info3	*rot;
	t_info3	*corrected;

	ray->ori->x_r = cam->ori->x_r;
	ray->ori->y_g = cam->ori->y_g;
	ray->ori->z_b = cam->ori->z_b;
	dir = rt_init_info3();
	dir->x_r = rt->j - scn->win_x / 2;
	dir->y_g = rt->i - scn->win_y / 2;
	dir->z_b = -scn->win_x / (2 * tan(cam->fov / 2));
	rt_math_normalize(dir);
	corrected = rt_init_info3();
	corrected->x_r = cam->vec->y_g;
	corrected->y_g = -cam->vec->x_r;
	corrected->z_b = cam->vec->z_b;
	rot = rt_image_rotation_xyz(dir->x_r, dir->y_g, dir->z_b, corrected);
	free(dir);
	free(corrected);
	rt_copy_info3(rot, ray->dir);
	free(rot);
}

void		rt_image_getorigin(t_info3 *hit_ori, t_ray *ray, double solution)
{
	hit_ori->x_r = ray->ori->x_r + ray->dir->x_r * solution;
	hit_ori->y_g = ray->ori->y_g + ray->dir->y_g * solution;
	hit_ori->z_b = ray->ori->z_b + ray->dir->z_b * solution;
}

double		rt_image_getdistance(t_info3 *hit_ori, t_info3 *light_ori)
{
	double	x;
	double	y;
	double	z;

	x = pow(light_ori->x_r - hit_ori->x_r, 2);
	y = pow(light_ori->y_g - hit_ori->y_g, 2);
	z = pow(light_ori->z_b - hit_ori->z_b, 2);
	return (pow(x + y + z, 0.5));
}

t_info3		*rt_image_getintensity(t_info3 *color, double intens)
{
	t_info3	*color_intens;

	color_intens = rt_init_info3();
	color_intens->x_r = color->x_r / 255.0 * intens;
	color_intens->y_g = color->y_g / 255.0 * intens;
	color_intens->z_b = color->z_b / 255.0 * intens;
	return (color_intens);
}

double		rt_image_rgbtoi(t_info3 *color)
{
	int		r;
	int		g;
	int		b;

	r = pow(color->x_r * 255 * 500, 1 / 2.2);
	g = pow(color->y_g * 255 * 500, 1 / 2.2);
	b = pow(color->z_b * 255 * 500, 1 / 2.2);
	return (r * 65536 + g * 256 + b);
}
