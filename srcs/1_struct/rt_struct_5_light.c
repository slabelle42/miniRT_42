/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct_5_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:05:09 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:05:10 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light		*rt_init_light(void)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		rt_exit(ERR_MALLOC);
	light->ori = rt_init_info3();
	light->intens = 0.0;
	light->color = rt_init_info3();
	light->next = NULL;
	return (light);
}

int			rt_add_light(t_light **lights, t_light *new_light)
{
	t_light	*tmp;

	if (lights && new_light)
	{
		if (!(*lights))
			*lights = new_light;
		else
		{
			tmp = *lights;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_light;
		}
		return (0);
	}
	return (-1);
}

static void	rt_delone_light(t_light *light)
{
	if (light)
	{
		if (light->ori)
			free(light->ori);
		if (light->color)
			free(light->color);
		free(light);
	}
}

void		rt_clear_lights(t_light **lights)
{
	t_light	*tmp;

	if (lights && *lights)
	{
		while (lights && *lights)
		{
			tmp = (*lights)->next;
			rt_delone_light(*lights);
			*lights = tmp;
		}
	}
}
