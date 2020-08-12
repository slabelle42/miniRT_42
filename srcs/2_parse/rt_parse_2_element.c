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
	if (amb->color->x_r < 0 || amb->color->x_r > 255
		|| amb->color->y_g < 0 || amb->color->y_g > 255
		|| amb->color->z_b < 0 || amb->color->z_b > 255)
		rt_parse_exit(rt, ERR_LIMIT);
}

void		rt_parse_camera(t_rt *rt, t_cam **cams, char *line)
{
	t_cam	*tmp;

	if (rt_add_camera(cams, rt_init_camera()) < 0)
		rt_parse_exit(rt, ERR_MALLOC);
	tmp = *cams;
	while (tmp->next)
		tmp = tmp->next;
	rt->i = 1;
	rt_parse_move(rt, line);
	rt_parse_info3(rt, tmp->ori, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, tmp->vec, line);
	rt_parse_move(rt, line);
	tmp->fov = rt_parse_atoi(rt, line) * M_PI / 180;
	if (tmp->fov < 0 || tmp->fov > 180)
		rt_parse_exit(rt, ERR_LIMIT);
	tmp = NULL;
	(rt->scn->cam_nb)++;
}

void		rt_parse_light(t_rt *rt, t_light **lights, char *line)
{
	t_light	*tmp;

	if (rt_add_light(lights, rt_init_light()) < 0)
		rt_parse_exit(rt, ERR_MALLOC);
	tmp = *lights;
	while (tmp->next)
		tmp = tmp->next;
	rt->i = 1;
	rt_parse_move(rt, line);
	rt_parse_info3(rt, tmp->ori, line);
	rt_parse_move(rt, line);
	tmp->intens = rt_parse_atod(rt, line);
	if (tmp->intens < 0 || tmp->intens > 1)
		rt_parse_exit(rt, ERR_LIMIT);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, tmp->color, line);
	if (tmp->color->x_r < 0 || tmp->color->x_r > 255
		|| tmp->color->y_g < 0 || tmp->color->y_g > 255
		|| tmp->color->z_b < 0 || tmp->color->z_b > 255)
		rt_parse_exit(rt, ERR_LIMIT);
	tmp = NULL;
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
