/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_1_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:01:53 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:03:01 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rt_parse_objects(t_rt *rt, char *line)
{
	if (line[0] == 's' && line[1] == 'p')
		rt_parse_sphere(rt, &rt->scn->objs, line);
	else if (line[0] == 'p' && line[1] == 'l')
		rt_parse_plane(rt, &rt->scn->objs, line);
	else if (line[0] == 's' && line[1] == 'q')
		rt_parse_square(rt, &rt->scn->objs, line);
	else if (line[0] == 'c' && line[1] == 'y')
		rt_parse_cylinder(rt, &rt->scn->objs, line);
	else if (line[0] == 't' && line[1] == 'r')
		rt_parse_triangle(rt, &rt->scn->objs, line);
	else
		rt_exit_parse(rt, ERR_ELEM_UNKN);
}

static void	rt_parse_line(t_rt *rt, char *line)
{
	if (line[0] == '\n' || line[0] == '\0')
		return ;
	else if (line[0] == 'R' && rt->scn->win_x < 0 && rt->scn->win_y < 0)
		rt_parse_resolution(rt, rt->scn, line);
	else if (line[0] == 'R')
		rt_exit_parse(rt, ERR_ELEM_UNIQ);
	else if (line[0] == 'A' && rt->scn->amb->intens < 0)
		rt_parse_ambiance(rt, rt->scn->amb, line);
	else if (line[0] == 'A')
		rt_exit_parse(rt, ERR_ELEM_UNIQ);
	else if (line[0] == 'c' && line[1] != 'y')
		rt_parse_camera(rt, &rt->scn->cams, line);
	else if (line[0] == 'l')
		rt_parse_light(rt, &rt->scn->lights, line);
	else if (line[0] == 's' && line[1] == 'h')
		rt_parse_shadow(rt, rt->scn, line);
	else
		rt_parse_objects(rt, line);
}

void		rt_parse(t_rt *rt, t_file *file)
{
	while ((file->ret = get_next_line(file->fd, &file->line)))
	{
		(file->line_nb)++;
		rt_parse_line(rt, file->line);
		free(file->line);
	}
	if (file->ret == -1)
		rt_exit_parse(rt, ERR_GNL);
	close(file->fd);
	rt_parse_checks(rt);
}
