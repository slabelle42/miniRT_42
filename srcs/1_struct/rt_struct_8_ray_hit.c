/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct_8_ray_hit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 10:55:16 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/02 10:56:11 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray		*rt_init_ray(void)
{
	t_ray	*ray;

	if (!(ray = ft_memalloc(sizeof(t_ray))))
		rt_exit(ERR_MALLOC);
	ray->ori = rt_init_info3();
	ray->dir = rt_init_info3();
	return (ray);
}

void		rt_clear_ray(t_ray *ray)
{
	if (ray)
	{
		if (ray->ori)
			free(ray->ori);
		if (ray->dir)
			free(ray->dir);
		free(ray);
	}
}

t_hit		*rt_init_hit(void)
{
	t_hit	*hit;

	if (!(hit = ft_memalloc(sizeof(t_hit))))
		rt_exit(ERR_MALLOC);
	hit->ray_light = rt_init_ray();
	hit->ray_shad = rt_init_ray();
	hit->ori = rt_init_info3();
	hit->norm = rt_init_info3();
	hit->color = rt_init_info3();
	return (hit);
}

void		rt_clear_hit(t_hit *hit)
{
	if (hit)
	{
		rt_clear_ray(hit->ray_light);
		rt_clear_ray(hit->ray_shad);
		if (hit->ori)
			free(hit->ori);
		if (hit->norm)
			free(hit->norm);
		if (hit->color)
			free(hit->color);
		free(hit);
	}
}
