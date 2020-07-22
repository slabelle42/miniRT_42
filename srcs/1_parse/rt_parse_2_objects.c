#include "minirt.h"

int				rt_parse_sphere(t_scn *scn, t_objs **objs, char *line)
{
	t_objs		*tmp;

	if (rt_add_object(objs, rt_init_object()) == -1)
		return (-1);
	tmp = *objs;
	while (tmp->next)
		tmp = tmp->next;
	scn->i = 2;
	tmp->type = 's';
	if (rt_parse_vector(scn, tmp->ori, line) == -1)
		return (-1);
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	tmp->size = rt_parse_todouble(scn, line);
	if (rt_parse_color(scn, tmp->color, line) == -1)
		return (-1);
	tmp = NULL;
	return (0);
}
