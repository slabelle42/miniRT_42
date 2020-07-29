/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_1_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:02:29 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:02:58 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			rt_parse_light(t_scn *scn, t_lights **lights, char *line)
{
	t_lights	*tmp;

	if (rt_add_light(lights, rt_init_light()) == -1)
		rt_exit_ko_line(42, scn, line);
	tmp = *lights;
	while (tmp->next)
		tmp = tmp->next;
	scn->i = 1;
	rt_parse_vector(scn, tmp->ori, line);
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	tmp->intens = rt_parse_todouble(scn, line) * 1000;
	if (tmp->intens < 0 || tmp->intens > 1000)
		rt_exit_ko_line(22, scn, line);
	tmp = NULL;
}

void			rt_parse_camera(t_scn *scn, t_cams **cams, char *line)
{
	t_cams		*tmp;

	if (rt_add_camera(cams, rt_init_camera()) == -1)
		rt_exit_ko_line(42, scn, line);
	tmp = *cams;
	while (tmp->next)
		tmp = tmp->next;
	scn->i = 1;
	rt_parse_vector(scn, tmp->ori, line);
	rt_parse_vector(scn, tmp->dir, line);
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	tmp->fov = rt_math_fov(rt_parse_toint(scn, line));
	if (tmp->fov < 0 || tmp->fov > 180)
		rt_exit_ko_line(21, scn, line);
	tmp = NULL;
}

void			rt_parse_window(t_scn *scn, char *line)
{
	scn->i = 1;
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	if (ft_isdigit(line[scn->i]))
		scn->win_w = rt_parse_toint(scn, line);
	else
		rt_exit_ko_line(14, scn, line);
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	if (ft_isdigit(line[scn->i]))
		scn->win_h = rt_parse_toint(scn, line);
	else
		rt_exit_ko_line(14, scn, line);
	if (scn->win_w < 1 || scn->win_h < 1)
		rt_exit_ko_line(12, scn, line);
}

void			rt_parse_line(t_scn *scn, char *line)
{
	if (line[0] == '\n' || line[0] == '\0')
		return ;
	else if (line[0] == 'R' && scn->win_w == 0 && scn->win_h == 0)
		rt_parse_window(scn, line);
	else if (line[0] == 'R')
		rt_exit_ko_line(11, scn, line);
//	else if (line[0] == 'A' && scn->amb_intens == -1)
//		rt_parse_ambiance(scn, line);
//	else if (line[0] == 'A')
//		rt_exit_ko_line(11, scn, line);
	else if (line[0] == 'c')
		rt_parse_camera(scn, &scn->cams, line);
	else if (line[0] == 'l')
		rt_parse_light(scn, &scn->lights, line);
	else if (line[0] == 's' && line[1] == 'p')
		rt_parse_sphere(scn, &scn->objs, line);
//	else
//		rt_exit_ko_line(10, scn, line);
}
