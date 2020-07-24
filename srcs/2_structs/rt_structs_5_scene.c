/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structs_5_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:05:09 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:05:10 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scn		*rt_init_scene(void)
{
	t_scn	*scn;

	if (!(scn = ft_memalloc(sizeof(t_scn))))
		return (NULL);
	scn->file_name = "";
	scn->win_h = 0;
	scn->win_w = 0;
	scn->cams = NULL;
	scn->lights = NULL;
	scn->objs = NULL;
	scn->mlx_ptr = NULL;
	scn->win_ptr = NULL;
	scn->img_ptr = NULL;
	scn->i = 0;
	scn->j = 0;
	scn->pix_intens = 0;
	if (!(scn->ori = rt_init_vector()))
		return (NULL);
	if (!(scn->color = rt_init_color()))
		return (NULL);
	return (scn);
}

static void	rt_clear_scene_structs(t_scn *scn)
{
	free(scn->ori);
	free(scn->color);
	free(scn);
}

void		rt_clear_scene(t_scn **scn,
				t_cams *cams, t_lights *lights, t_objs *objs)
{
	if (cams)
		rt_clear_cameras(&cams);
	if (lights)
		rt_clear_lights(&lights);
	if (objs)
		rt_clear_objects(&objs);
	if (scn && *scn)
	{
		rt_clear_cameras(&cams);
		rt_clear_scene_structs(*scn);
	}
}
