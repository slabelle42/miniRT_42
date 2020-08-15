/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_3_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 20:24:57 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/14 20:25:01 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		rt_image_checkinside_square(t_info3 *hit_ori, t_obj *obj)
{
	t_info3		*rot;
	t_info3		*diff;
	double		res1;
	double		res2;

	rot = rt_image_rotation_xyz(obj->size1, 0.0, 0.0, obj->vec);
	diff = rt_info3_diff(hit_ori, obj->ori);
	res1 = rt_info3_dot(diff, rot) / sqrt(rt_info3_dot(rot, rot));
	free(rot);
	free(diff);
	rot = rt_image_rotation_xyz(0.0, obj->size1, 0.0, obj->vec);
	diff = rt_info3_diff(hit_ori, obj->ori);
	res2 = rt_info3_dot(diff, rot) / sqrt(rt_info3_dot(rot, rot));
	free(rot);
	free(diff);
	if (res1 >= -obj->size1 / 2 && res1 <= obj->size1 / 2
		&& res2 >= -obj->size1 / 2 && res2 <= obj->size1 / 2)
		return (1);
	return (0);
}

double			rt_image_tryhit_square(t_hit *hit, t_ray *ray, t_obj *obj)
{
	t_info3		*norm;
	t_info3		*diff;
	double		solution;

	norm = rt_image_getnormal_plane(ray, obj);
	diff = rt_info3_diff(obj->ori, ray->ori);
	solution = rt_info3_dot(diff, norm) / rt_info3_dot(ray->dir, norm);
	free(norm);
	free(diff);
	hit->ori->x_r = ray->ori->x_r + ray->dir->x_r * solution;
	hit->ori->y_g = ray->ori->y_g + ray->dir->y_g * solution;
	hit->ori->z_b = ray->ori->z_b + ray->dir->z_b * solution;
	if (rt_image_checkinside_square(hit->ori, obj))
		return (solution);
	return (-1.0);
}

void			rt_image_gethitpoint_square(t_hit *hit, t_ray *ray,
					t_obj *obj_hit)
{
	double		solution;
	t_info3		*norm;

	solution = rt_image_tryhit_square(hit, ray, obj_hit);
	hit->ori->x_r = ray->ori->x_r + ray->dir->x_r * solution;
	hit->ori->y_g = ray->ori->y_g + ray->dir->y_g * solution;
	hit->ori->z_b = ray->ori->z_b + ray->dir->z_b * solution;
	norm = rt_image_getnormal_plane(ray, obj_hit);
	if (rt_math_cosine(norm, ray->dir) > 0)
	{
		norm->x_r *= -1.0;
		norm->y_g *= -1.0;
		norm->z_b *= -1.0;
	}
	rt_copy_info3(norm, hit->norm);
	free(norm);
	rt_copy_info3(obj_hit->color, hit->color);
}
