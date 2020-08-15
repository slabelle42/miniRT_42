/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_2_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:05:26 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/13 21:05:33 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_info3			*rt_image_getnormal_plane(t_ray *ray, t_obj *obj)
{
	t_info3		*norm_rot;
	t_info3		*norm_inv;

	norm_rot = rt_image_rotation_xyz(0.0, 0.0, 1.0, obj->vec);
	if (rt_math_cosine(norm_rot, ray->dir) > 0)
	{
		norm_inv = rt_init_info3();
		rt_fill_info3(norm_inv, -1.0, -1.0, -1.0);
		rt_info3_mul(norm_inv, norm_rot);
		free(norm_rot);
		return (norm_inv);
	}
	else
		return (norm_rot);
}

double			rt_image_tryhit_plane(t_ray *ray, t_obj *obj)
{
	t_info3		*norm;
	t_info3		*diff;
	double		dot;
	double		denom;

	norm = rt_image_getnormal_plane(ray, obj);
	diff = rt_info3_diff(obj->ori, ray->ori);
	dot = rt_info3_dot(diff, norm);
	free(diff);
	denom = rt_info3_dot(ray->dir, norm);
	free(norm);
	return (dot / denom);
}

void			rt_image_gethitpoint_plane(t_hit *hit, t_ray *ray,
					t_obj *obj_hit)
{
	double		solution;
	t_info3		*norm;

	solution = rt_image_tryhit_plane(ray, obj_hit);
	hit->ori->x_r = ray->ori->x_r + ray->dir->x_r * solution;
	hit->ori->y_g = ray->ori->y_g + ray->dir->y_g * solution;
	hit->ori->z_b = ray->ori->z_b + ray->dir->z_b * solution;
	norm = rt_image_getnormal_plane(ray, obj_hit);
	rt_copy_info3(norm, hit->norm);
	free(norm);
	rt_copy_info3(obj_hit->color, hit->color);
}
