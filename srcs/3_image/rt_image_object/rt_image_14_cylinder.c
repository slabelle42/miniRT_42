/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_14_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:13:30 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/15 20:13:37 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_info3	*rt_image_getnormal_cylinder(t_ray *ray, t_info3 *axis,
					t_info3 *diff)
{
	double		dot;
	t_info3		*dot3;
	t_info3		*norm;

	dot = rt_info3_dot(axis, diff);
	dot3 = rt_init_info3();
	rt_fill_info3(dot3, dot, dot, dot);
	rt_info3_mul(axis, dot3);
	norm = rt_info3_diff(diff, dot3);
	free(dot3);
	rt_math_normalize(norm);
	if (rt_math_cosine(norm, ray->dir) > 0)
	{
		norm->x_r *= -1.0;
		norm->y_g *= -1.0;
		norm->z_b *= -1.0;
	}
	return (norm);
}

static int		rt_image_checklimits_cylinder(t_hit *hit, t_obj *obj,
					t_info3 *axis)
{
	t_info3		*diff;
	double		dot;
	t_info3		*size;
	t_info3		*up;

	diff = rt_info3_diff(hit->ori, obj->ori);
	dot = rt_info3_dot(axis, diff) >= 0;
	free(diff);
	if (dot)
	{
		size = rt_init_info3();
		rt_fill_info3(size, obj->size2, obj->size2, obj->size2);
		rt_info3_mul(size, axis);
		up = rt_init_info3();
		rt_info3_add(up, size);
		free(size);
		rt_info3_add(up, obj->ori);
		diff = rt_info3_diff(hit->ori, up);
		free(up);
		dot = rt_info3_dot(axis, diff) <= 0;
		free(diff);
		return (dot);
	}
	return (0);
}

static t_info3	*rt_image_getabc_cylinder(t_ray *ray, double radius,
					t_info3 *axis, t_info3 *diff)
{
	t_info3		*abc;
	t_info3		*d;
	t_info3		*e;
	t_info3		*f;

	abc = rt_init_info3();
	d = rt_init_info3();
	rt_fill_info3(d,
		axis->x_r * rt_info3_dot(ray->dir, axis),
		axis->y_g * rt_info3_dot(ray->dir, axis),
		axis->z_b * rt_info3_dot(ray->dir, axis));
	e = rt_info3_diff(ray->dir, d);
	abc->x_r = rt_info3_dot(e, e);
	rt_fill_info3(d,
		axis->x_r * rt_info3_dot(diff, axis),
		axis->y_g * rt_info3_dot(diff, axis),
		axis->z_b * rt_info3_dot(diff, axis));
	f = rt_info3_diff(diff, d);
	abc->y_g = 2 * rt_info3_dot(e, f);
	abc->z_b = rt_info3_dot(f, f) - radius * radius;
	free(d);
	free(e);
	free(f);
	return (abc);
}

double			rt_image_tryhit_cylinder(t_hit *hit, t_ray *ray, t_obj *obj)
{
	t_info3		*axis;
	t_info3		*diff;
	t_info3		*abc;
	double		solution;

	axis = rt_image_rotation_xyz(0.0, 1.0, 0.0, obj->vec);
	rt_math_normalize(axis);
	diff = rt_info3_diff(ray->ori, obj->ori);
	abc = rt_image_getabc_cylinder(ray, obj->size1 / 2, axis, diff);
	free(diff);
	solution = rt_math_solution_cylinder(abc->x_r, abc->y_g, abc->z_b, 0);
	rt_image_getorigin(hit->ori, ray, solution);
	if (!rt_image_checklimits_cylinder(hit, obj, axis))
		solution = -1.0;
	if (solution <= 0.000001)
	{
		solution = rt_math_solution_cylinder(abc->x_r, abc->y_g, abc->z_b, 1);
		rt_image_getorigin(hit->ori, ray, solution);
		if (!rt_image_checklimits_cylinder(hit, obj, axis))
			solution = -1.0;
	}
	free(axis);
	free(abc);
	return (solution);
}

void			rt_image_gethitpoint_cylinder(t_hit *hit, t_ray *ray,
					t_obj *obj_hit)
{
	double		solution;
	t_info3		*axis;
	t_info3		*diff;
	t_info3		*norm;

	solution = rt_image_tryhit_cylinder(hit, ray, obj_hit);
	rt_image_getorigin(hit->ori, ray, solution);
	axis = rt_image_rotation_xyz(0.0, 1.0, 0.0, obj_hit->vec);
	rt_math_normalize(axis);
	diff = rt_info3_diff(hit->ori, obj_hit->ori);
	norm = rt_image_getnormal_cylinder(ray, axis, diff);
	free(axis);
	free(diff);
	rt_copy_info3(norm, hit->norm);
	free(norm);
	rt_copy_info3(obj_hit->color, hit->color);
}
