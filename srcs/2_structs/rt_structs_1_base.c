/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structs_1_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:04:22 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:04:41 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		*rt_init_vector(void)
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

t_color		*rt_init_color(void)
{
	t_color	*color;

	if (!(color = ft_memalloc(sizeof(t_color))))
		return (NULL);
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}

int			rt_fill_color(t_scn *scn, t_color *color, char *line)
{
	if (ft_isdigit(line[scn->i]))
		color->r = rt_parse_toint(scn, line);
	if (line[scn->i] == ',')
		(scn->i)++;
	else
		return (-1);
	if (ft_isdigit(line[scn->i]))
		color->g = rt_parse_toint(scn, line);
	if (line[scn->i] == ',')
		(scn->i)++;
	else
		return (-1);
	if (ft_isdigit(line[scn->i]))
		color->b = rt_parse_toint(scn, line);
	return (0);
}
