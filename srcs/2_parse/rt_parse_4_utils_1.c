/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_4_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:03:51 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:04:08 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			rt_parse_move(t_rt *rt, char *line)
{
	while (line[rt->i] == ' ' || line[rt->i] == '\t')
		(rt->i)++;
	if (line[rt->i] == '\0')
		rt_exit_parse(rt, ERR_ELEM_WRG);
}

int				rt_parse_atoi(t_rt *rt, char *line)
{
	int			nb;

	if (ft_isdigit(line[rt->i]))
	{
		nb = 0;
		while (ft_isdigit(line[rt->i]))
		{
			nb = (nb * 10) + (line[rt->i] - '0');
			(rt->i)++;
		}
		return (nb);
	}
	rt_exit_parse(rt, ERR_ELEM_WRG);
	return (0);
}

static double	rt_parse_getfloat(t_rt *rt, char *line)
{
	double		f;
	int			len;

	(rt->i)++;
	if (!(ft_isdigit(line[rt->i])))
		rt_exit_parse(rt, ERR_ELEM_WRG);
	f = 0;
	len = 0;
	while (ft_isdigit(line[rt->i]))
	{
		f = (f * 10) + (line[rt->i] - '0');
		(rt->i)++;
		len++;
	}
	if (len > 5)
		rt_exit_parse(rt, ERR_INFO_DIGIT);
	while (len-- > 0)
		f *= 0.1;
	return (f);
}

double			rt_parse_atod(t_rt *rt, char *line)
{
	double		sign;
	double		nb;

	sign = 1;
	if (line[rt->i] == '-')
	{
		sign = -1;
		(rt->i)++;
	}
	if (ft_isdigit(line[rt->i]))
	{
		nb = 0;
		while (ft_isdigit(line[rt->i]))
		{
			nb = (nb * 10) + (line[rt->i] - '0');
			(rt->i)++;
		}
		if (line[rt->i] == '.')
			nb += rt_parse_getfloat(rt, line);
		return (sign * nb);
	}
	rt_exit_parse(rt, ERR_ELEM_WRG);
	return (0);
}

void			rt_parse_info3(t_rt *rt, t_info3 *info3, char *line)
{
	int			info_nb;

	if (!ft_isdigit(line[rt->i]) && line[rt->i] != '-')
		rt_exit_parse(rt, ERR_ELEM_WRG);
	info_nb = 0;
	while (++info_nb <= 3)
	{
		if (ft_isdigit(line[rt->i]) || line[rt->i] == '-')
		{
			if (info_nb == 1)
				info3->x_r = rt_parse_atod(rt, line);
			else if (info_nb == 2)
				info3->y_g = rt_parse_atod(rt, line);
			else if (info_nb == 3)
				info3->z_b = rt_parse_atod(rt, line);
		}
		else
			rt_exit_parse(rt, ERR_ELEM_WRG);
		if (line[rt->i] == ',')
			(rt->i)++;
		else if (info_nb < 3)
			rt_exit_parse(rt, ERR_ELEM_WRG);
	}
}
