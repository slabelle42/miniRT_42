/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_3_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:03:51 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:04:08 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				rt_parse_toint(t_scn *scn, char *line)
{
	int			n;

	n = 0;
	while (ft_isdigit(line[scn->i]))
	{
		n = (n * 10) + (line[scn->i] - '0');
		(scn->i)++;
	}
	return (n);
}

static double	rt_parse_todouble_float(t_scn *scn, char *line, int d)
{
	double		f;
	int			len;

	(scn->i)++;
	if (!(ft_isdigit(line[scn->i])))
		rt_exit_ko_line(16, scn, line);
	f = 0;
	len = 0;
	while (ft_isdigit(line[scn->i]))
	{
		f = (f * 10) + (line[scn->i] - '0');
		(scn->i)++;
		len++;
	}
	if (len > 10)
		rt_exit_ko_line(17, scn, line);
	while (len-- > 0)
		f *= 0.1;
	return (d + f);
}

double			rt_parse_todouble(t_scn *scn, char *line)
{
	double		sign;
	double		d;

	sign = 1;
	if (line[scn->i] == '-')
	{
		sign = -1;
		(scn->i)++;
	}
	d = 0;
	while (ft_isdigit(line[scn->i]))
	{
		d = (d * 10) + (line[scn->i] - '0');
		(scn->i)++;
	}
	if (line[scn->i] == '.')
		d = rt_parse_todouble_float(scn, line, d);
	return (sign * d);
}

void			rt_parse_vector(t_scn *scn, t_vec *vec, char *line)
{
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	if (ft_isdigit(line[scn->i]) || line[scn->i] == '-')
		rt_fill_vector(scn, vec, line);
	else
		rt_exit_ko_line(13, scn, line);
}

void			rt_parse_color(t_scn *scn, t_color *color, char *line)
{
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	if (ft_isdigit(line[scn->i]))
		rt_fill_color(scn, color, line);
	else
		rt_exit_ko_line(13, scn, line);
}
