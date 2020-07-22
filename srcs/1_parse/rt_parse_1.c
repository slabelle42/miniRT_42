#include "minirt.h"

int				rt_parse_light(t_scn *scn, t_lights **lights, char *line)
{
	t_lights	*tmp;

	if (rt_add_light(lights, rt_init_light()) == -1)
		return (-1);
	tmp = *lights;
	while (tmp->next)
		tmp = tmp->next;
	scn->i = 1;
	if (rt_parse_vector(scn, tmp->ori, line) == -1)
		return (-1);
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	tmp->intens = rt_parse_todouble(scn, line);
	tmp = NULL;
	return (0);
}

int				rt_parse_camera(t_scn *scn, t_cams **cams, char *line)
{
	t_cams		*tmp;

	if (rt_add_camera(cams, rt_init_camera()) == -1)
		return (-1);
	tmp = *cams;
	while (tmp->next)
		tmp = tmp->next;
	scn->i = 1;
	if (rt_parse_vector(scn, tmp->ori, line) == -1)
		return (-1);
	if (rt_parse_vector(scn, tmp->dir, line) == -1)
		return (-1);
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	tmp->fov = rt_math_fov(rt_parse_toint(scn, line));
	tmp = NULL;
	return (0);
}

int				rt_parse_window(t_scn *scn, char *line)
{
	scn->i = 1;
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	if (ft_isdigit(line[scn->i]))
		scn->win_W = rt_parse_toint(scn, line);
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	if (ft_isdigit(line[scn->i]))
		scn->win_H = rt_parse_toint(scn, line);
	if (scn->win_W < 1 || scn->win_H < 1)
		return (-1);
	return (0);
}

int				rt_parse_line(t_scn *scn, char *line)
{
	if (line[0])
	{
		if (line[0] == 'R')
			return (rt_parse_window(scn, line));
//		else if (line[0] == 'A')
//			return (rt_parse_ambiance(scn, line));
		else if (line[0] == 'c')
			return (rt_parse_camera(scn, &scn->cams, line));
		else if (line[0] == 'l')
			return (rt_parse_light(scn, &scn->lights, line));
		else if (line[0] == 's' && line[1] == 'p')
			return (rt_parse_sphere(scn, &scn->objs, line));
//		else
//			return (-1);
	}
	return (0);
}
