/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_15_triangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 20:12:07 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/17 20:12:20 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		rt_image_checkinside_triangle(t_info3 *hit_ori, t_info3 *x,
					t_info3 *y, t_info3 *norm)
{
	t_info3		*diff1;
	t_info3		*diff2;
	t_info3		*cross;
	int			check;

	diff1 = rt_info3_diff(y, x);
	diff2 = rt_info3_diff(hit_ori, x);
	cross = rt_init_info3();
	cross->x_r = diff1->y_g * diff2->z_b - diff1->z_b * diff2->y_g;
	cross->y_g = diff1->z_b * diff2->x_r - diff1->x_r * diff2->z_b;
	cross->z_b = diff1->x_r * diff2->y_g - diff1->y_g * diff2->x_r;
	free(diff1);
	free(diff2);
	check = 0;
	if (rt_info3_dot(norm, cross) >= 0)
		check = 1;
	free(cross);
	return (check);
}

static t_info3	*rt_image_getnormal_triangle(t_obj *obj)
{
	t_info3		*ab;
	t_info3		*ac;
	t_info3		*norm;

	ab = rt_info3_diff(obj->b, obj->a);
	ac = rt_info3_diff(obj->c, obj->a);
	norm = rt_init_info3();
	norm->x_r = ab->y_g * ac->z_b - ab->z_b * ac->y_g;
	norm->y_g = ab->z_b * ac->x_r - ab->x_r * ac->z_b;
	norm->z_b = ab->x_r * ac->y_g - ab->y_g * ac->x_r;
	free(ab);
	free(ac);
	rt_math_normalize(norm);
	return (norm);
}

double			rt_image_tryhit_triangle(t_hit *hit, t_ray *ray, t_obj *obj)
{
	t_info3		*norm;
	t_info3		*diff;
	double		solution;

	norm = rt_image_getnormal_triangle(obj);
	diff = rt_info3_diff(obj->a, ray->ori);
	solution = rt_info3_dot(diff, norm) / rt_info3_dot(ray->dir, norm);
	free(diff);
	rt_image_getorigin(hit->ori, ray, solution);
	if (!(rt_image_checkinside_triangle(hit->ori, obj->a, obj->b, norm)
		&& rt_image_checkinside_triangle(hit->ori, obj->b, obj->c, norm)
		&& rt_image_checkinside_triangle(hit->ori, obj->c, obj->a, norm)))
		solution = -1.0;
	free(norm);
	return (solution);
}

void			rt_image_gethitpoint_triangle(t_hit *hit, t_ray *ray,
					t_obj *obj_hit)
{
	double		solution;
	t_info3		*norm;

	solution = rt_image_tryhit_triangle(hit, ray, obj_hit);
	rt_image_getorigin(hit->ori, ray, solution);
	norm = rt_image_getnormal_triangle(obj_hit);
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
