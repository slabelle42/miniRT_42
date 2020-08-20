/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct_7_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 11:04:52 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/02 11:04:57 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scn		*rt_init_scene(void)
{
	t_scn	*scn;

	if (!(scn = ft_memalloc(sizeof(t_scn))))
		rt_exit(ERR_MALLOC);
	scn->win_x = -1;
	scn->win_y = -1;
	scn->amb = rt_init_ambiance();
	scn->cams = NULL;
	scn->cam_nb = 0;
	scn->cam_current = 1;
	scn->lights = NULL;
	scn->objs = NULL;
	scn->is_shad = 1;
	return (scn);
}

void		rt_clear_scene_elements(t_amb *amb, t_cam *cams, t_light *lights,
				t_obj *objs)
{
	rt_clear_ambiance(amb);
	rt_clear_cameras(&cams);
	rt_clear_lights(&lights);
	rt_clear_objects(&objs);
}

void		rt_clear_scene(t_scn **scn)
{
	if (scn && *scn)
		free(*scn);
}
