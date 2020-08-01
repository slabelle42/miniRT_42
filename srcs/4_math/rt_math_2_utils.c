/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_2_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:06:18 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:06:20 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		rt_math_fov(double fov)
{
	return (fov * M_PI / 180);
}

double		rt_math_norm2(t_vec *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

void		rt_math_normalize(t_vec *vec)
{
	double	norm;

	norm = sqrt(rt_math_norm2(vec));
	vec->x /= norm;
	vec->y /= norm;
	vec->z /= norm;
}

void		rt_math_pos_norm(t_scn *scn, t_cams *cam, t_intersect *intersect)
{
	intersect->pos->x = cam->ori->x
		+ intersect->solution * cam->dir->x;
	intersect->pos->y = cam->ori->y
		+ intersect->solution * cam->dir->y;
	intersect->pos->z = cam->ori->z
		+ intersect->solution * cam->dir->z;
	intersect->norm->x = intersect->pos->x - scn->ori->x;
	intersect->norm->y = intersect->pos->y - scn->ori->y;
	intersect->norm->z = intersect->pos->z - scn->ori->z;
	rt_math_normalize(intersect->norm);
}
