/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_display_2_shadow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:51:41 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/02 17:51:47 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	rt_shadow_getdistance(t_vec *ori, t_intersect *intersect,
					t_shad *shad)
{
	shad->diff->x = ori->x - intersect->pos->x;
	shad->diff->y = ori->y - intersect->pos->y;
	shad->diff->z = ori->z - intersect->pos->z;
	return (rt_math_norm2(shad->diff));
}

static void		rt_shadow_epsilon(t_vec *ori, t_vec *norm)
{
	ori->x += 0.01 * norm->x;
	ori->y += 0.01 * norm->y;
	ori->z += 0.01 * norm->z;
}

static void		rt_shadow_getrayparams(t_scn *scn, t_intersect *intersect,
					t_cams *ray)
{
	ray->ori->x = intersect->pos->x;
	ray->ori->y = intersect->pos->y;
	ray->ori->z = intersect->pos->z;
	rt_shadow_epsilon(ray->ori, intersect->norm);
	ray->dir->x = scn->lights->ori->x - intersect->pos->x;
	ray->dir->y = scn->lights->ori->y - intersect->pos->y;
	ray->dir->z = scn->lights->ori->z - intersect->pos->z;
	rt_math_normalize(ray->dir);
}

int				rt_display_shadow(t_scn *scn, t_intersect *intersect)
{
	int			ret;
	t_shad		*shad;

	ret = 0;
	if (scn->shad == 0)
		return (ret);
	if (!(shad = rt_init_shadow()))
		rt_exit_ko_scn(42, scn);
	rt_shadow_getrayparams(scn, intersect, shad->ray);
	rt_display_object(scn, shad->ray, shad->intersect);
	if (shad->intersect->solution > -1)
	{
		shad->d_light2 = rt_shadow_getdistance(scn->lights->ori, intersect,
			shad);
		shad->d_obj2 = rt_shadow_getdistance(scn->ori, intersect, shad);
		if (shad->d_obj2 < shad->d_light2)
			ret = 1;
	}
	rt_clear_shadow(&shad);
	return (ret);
}
