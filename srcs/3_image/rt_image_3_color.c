/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_3_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:51:41 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/02 17:51:47 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_info3	*rt_image_getlightcolor(t_hit *hit, t_light *light)
{
	double		intens;
	t_info3		*light_color;

	intens = rt_math_lambertian(hit, light);
	light_color = rt_image_getintensity(light->color, intens);
	return (light_color);
}

static int		rt_image_checkshadow(t_scn *scn, t_hit *hit, t_obj *obj_hit,
					t_light *light)
{
	int			ret;
	t_obj		*obj;
	double		solution;
	double		light_distance;
	double		obj_distance;

	ret = 0;
	obj = scn->objs;
	while (obj && !ret)
	{
		solution = rt_image_tryhit(hit->ray_shad, obj);
		if (obj != obj_hit && solution > -1)
		{
			light_distance = rt_image_getdistance(hit->ori, light->ori);
			obj_distance = rt_image_getdistance(hit->ori, obj->ori);
			if (obj_distance < light_distance)
				ret = 1;
		}
		obj = obj->next;
	}
	obj = NULL;
	return (ret);
}

static t_info3	*rt_image_lightscolor(t_scn *scn, t_hit *hit, t_ray *ray,
					t_obj *obj_hit)
{
	t_light		*light;
	t_info3		*diff;
	t_info3		*light_color;
	t_info3		*pixel_color;

	light = scn->lights;
	pixel_color = rt_init_info3();
	while (light)
	{
		rt_copy_info3(hit->ori, ray->ori);
		diff = rt_info3_diff(light->ori, hit->ori);
		rt_math_normalize(diff);
		rt_copy_info3(diff, ray->dir);
		free(diff);
		if (!rt_image_checkshadow(scn, hit, obj_hit, light)
			|| !scn->is_shad)
		{
			light_color = rt_image_getlightcolor(hit, light);
			rt_info3_add(pixel_color, light_color);
			free(light_color);
		}
		light = light->next;
	}
	light = NULL;
	return (pixel_color);
}

static void		rt_image_gethitpoint(t_hit *hit, t_ray *ray, t_obj *obj_hit)
{
	if (obj_hit->type == 's')
		rt_image_gethitpoint_sphere(hit, ray, obj_hit);
}

t_info3			*rt_image_getcolor(t_scn *scn, t_amb *amb, t_hit *hit,
					t_obj *obj_hit)
{
	t_info3		*pixel_color;
	t_info3		*amb_color;
	t_info3		*obj_color;

	rt_image_gethitpoint(hit, hit->ray_light, obj_hit);
	pixel_color = rt_image_lightscolor(scn, hit, hit->ray_shad, obj_hit);
	amb_color = rt_image_getintensity(amb->color, amb->intens);
	rt_info3_add(pixel_color, amb_color);
	obj_color = rt_image_getintensity(hit->color, 1.0);
	rt_info3_mul(pixel_color, obj_color);
	rt_info3_limit(pixel_color, 1.0);
	free(amb_color);
	free(obj_color);
	return (pixel_color);
}
