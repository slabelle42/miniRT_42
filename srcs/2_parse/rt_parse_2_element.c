/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_2_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:02:29 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:02:58 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		rt_parse_resolution(t_rt *rt, t_scn *scn, char *line)
{
	scn->win_x = 0;
	scn->win_y = 0;
	rt->i = 1;
	rt_parse_move(rt, line);
	scn->win_x = rt_parse_atoi(rt, line);
	rt_parse_move(rt, line);
	scn->win_y = rt_parse_atoi(rt, line);
	if (scn->win_x == 0 || scn->win_y == 0)
		rt_parse_exit(rt, ERR_INFO_NULL);
}

void		rt_parse_ambiance(t_rt *rt, t_amb *amb, char *line)
{
	rt->i = 1;
	rt_parse_move(rt, line);
	amb->intens = rt_parse_atod(rt, line);
	if (amb->intens < 0 || amb->intens > 1)
		rt_parse_exit(rt, ERR_LIMIT);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, amb->color, line);
	rt_parse_colorlimits(rt, amb->color);
}

void		rt_parse_camera(t_rt *rt, t_cam **cams, char *line)
{
	t_cam	*cam;

	if (rt_add_camera(cams, rt_init_camera()) < 0)
		rt_parse_exit(rt, ERR_MALLOC);
	cam = *cams;
	while (cam->next)
		cam = cam->next;
	rt->i = 1;
	rt_parse_move(rt, line);
	rt_parse_info3(rt, cam->ori, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, cam->vec, line);
	rt_parse_veclimits(rt, cam->vec);
	rt_parse_move(rt, line);
	cam->fov = rt_parse_atoi(rt, line) * M_PI / 180;
	if (cam->fov < 0 || cam->fov > 180)
		rt_parse_exit(rt, ERR_LIMIT);
	cam = NULL;
	(rt->scn->cam_nb)++;
}

void		rt_parse_light(t_rt *rt, t_light **lights, char *line)
{
	t_light	*light;

	if (rt_add_light(lights, rt_init_light()) < 0)
		rt_parse_exit(rt, ERR_MALLOC);
	light = *lights;
	while (light->next)
		light = light->next;
	rt->i = 1;
	rt_parse_move(rt, line);
	rt_parse_info3(rt, light->ori, line);
	rt_parse_move(rt, line);
	light->intens = rt_parse_atod(rt, line);
	if (light->intens < 0 || light->intens > 1)
		rt_parse_exit(rt, ERR_LIMIT);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, light->color, line);
	rt_parse_colorlimits(rt, light->color);
	light = NULL;
}

void		rt_parse_shadow(t_rt *rt, t_scn *scn, char *line)
{
	rt->i = 2;
	rt_parse_move(rt, line);
	if (line[rt->i] == '0')
		scn->is_shad = 0;
	else
		rt_parse_exit(rt, ERR_SHAD);
}
