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
	scn->win_h = 0;
	scn->win_w = 0;
	scn->amb_intens = -1;
	scn->amb_r = 0;
	scn->amb_g = 0;
	scn->amb_b = 0;
	scn->cams = NULL;
	scn->cams_total = 0;
	scn->cams_current = 0;
	scn->lights = NULL;
	scn->objs = NULL;
	scn->mlx_ptr = NULL;
	scn->win_ptr = NULL;
	scn->img_ptr = NULL;
	scn->i = 0;
	scn->j = 0;
	scn->pix_intens = 0;
	if (!(scn->ori = rt_init_vector())
		|| !(scn->color = rt_init_color()))
		return (NULL);
	return (scn);
}

void		rt_fill_scene(t_scn *scn, char *file_name)
{
	scn->file_name = file_name;
	scn->line_nb = 0;
	scn->loop = 0;
}

static void	rt_clear_scene_structs(t_scn *scn)
{
	free(scn->ori);
	free(scn->color);
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
		rt_clear_scene_structs(*scn);
		free(*scn);
	}
}
