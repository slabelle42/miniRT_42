/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structs_7_shadow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 10:55:16 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/02 10:56:11 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shad			*rt_init_shadow(void)
{
	t_shad		*shad;

	if (!(shad = ft_memalloc(sizeof(t_shad))))
		return (NULL);
	if (!(shad->ray = rt_init_camera()))
		return (NULL);
	if (!(shad->intersect = rt_init_intersection()))
		return (NULL);
	if (!(shad->diff = rt_init_vector()))
		return (NULL);
	shad->d_light2 = 0;
	shad->d_obj2 = 0;
	return (shad);
}

static void		rt_clear_shadow_structs(t_shad *shad)
{
	free(shad->ray);
	free(shad->intersect);
	free(shad->diff);
}

void			rt_clear_shadow(t_shad **shad)
{
	if (shad && *shad)
	{
		rt_clear_shadow_structs(*shad);
		free(*shad);
	}
}
