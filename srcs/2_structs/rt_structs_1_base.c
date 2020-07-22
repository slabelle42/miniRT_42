#include "minirt.h"

t_vec		*rt_init_vector()
{
	t_vec	*vec;

	if (!(vec = ft_memalloc(sizeof(t_vec))))
		return (NULL);
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
	return (vec);
}

int			rt_fill_vector(t_scn *scn, t_vec *vec, char *line)
{
	if (ft_isdigit(line[scn->i]) || line[scn->i] == '-')
		vec->x = rt_parse_todouble(scn, line);
	if (line[scn->i] == ',')
		(scn->i)++;
	else
		return (-1);
	if (ft_isdigit(line[scn->i]) || line[scn->i] == '-')
		vec->y = rt_parse_todouble(scn, line);
	if (line[scn->i] == ',')
		(scn->i)++;
	else
		return (-1);
	if (ft_isdigit(line[scn->i]) || line[scn->i] == '-')
		vec->z = rt_parse_todouble(scn, line);
	return (0);
}

t_color		*rt_init_color()
{
	t_color	*color;

	if (!(color = ft_memalloc(sizeof(t_color))))
		return (NULL);
	color->R = 0;
	color->G = 0;
	color->B = 0;
	return (color);
}

int			rt_fill_color(t_scn *scn, t_color *color, char *line)
{
	if (ft_isdigit(line[scn->i]))
		color->R = rt_parse_toint(scn, line);
	if (line[scn->i] == ',')
		(scn->i)++;
	else
		return (-1);
	if (ft_isdigit(line[scn->i]))
		color->G = rt_parse_toint(scn, line);
	if (line[scn->i] == ',')
		(scn->i)++;
	else
		return (-1);
	if (ft_isdigit(line[scn->i]))
		color->B = rt_parse_toint(scn, line);
	return (0);
}
