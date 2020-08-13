/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_2_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:06:10 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:06:11 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		rt_image_tryhit(t_ray *ray, t_obj *obj)
{
	if (obj->type == 's')
		return (rt_image_tryhit_sphere(ray, obj));
	return (1000000.0);
}

t_obj		*rt_image_getobjhit(t_scn *scn, t_hit *hit)
{
	t_obj	*obj;
	t_obj	*obj_hit;
	double	solution;
	double	obj_solution;

	obj = scn->objs;
	obj_hit = NULL;
	solution = 1000000.0;
	while (obj)
	{
		obj_solution = rt_image_tryhit(hit->ray_light, obj);
		if (obj_solution < solution && obj_solution > -1)
		{
			solution = obj_solution;
			obj_hit = obj;
		}
		obj = obj->next;
	}
	obj = NULL;
	return (obj_hit);
}
