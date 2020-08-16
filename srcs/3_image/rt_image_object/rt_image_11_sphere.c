/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_11_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 12:39:40 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/12 12:39:46 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			rt_image_tryhit_sphere(t_ray *ray, t_obj *obj)
{
	t_info3		*diff;
	double		a;
	double		b;
	double		c;

	diff = rt_info3_diff(ray->ori, obj->ori);
	a = 1;
	b = 2 * rt_info3_dot(ray->dir, diff);
	c = rt_info3_dot(diff, diff) - obj->size1 * obj->size1;
	free(diff);
	return (rt_math_solution_sphere(a, b, c));
}

void			rt_image_gethitpoint_sphere(t_hit *hit, t_ray *ray,
					t_obj *obj_hit)
{
	double		solution;
	t_info3		*diff;

	solution = rt_image_tryhit_sphere(ray, obj_hit);
	rt_image_getorigin(hit->ori, ray, solution);
	diff = rt_info3_diff(hit->ori, obj_hit->ori);
	rt_math_normalize(diff);
	if (rt_math_cosine(diff, ray->dir) > 0)
	{
		diff->x_r *= -1.0;
		diff->y_g *= -1.0;
		diff->z_b *= -1.0;
	}
	rt_copy_info3(diff, hit->norm);
	free(diff);
	rt_copy_info3(obj_hit->color, hit->color);
}
