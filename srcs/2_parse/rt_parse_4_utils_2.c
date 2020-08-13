/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_4_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:03:51 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:04:08 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_parse_exit(t_rt *rt, int error_nb)
{
	ft_putstr_fd("( Stop on line ", 1);
	ft_putnbr_fd(rt->file->line_nb, 1);
	ft_putendl_fd(" )", 1);
	rt_exit(error_nb);
}

void	rt_parse_colorlimits(t_rt *rt, t_info3 *color)
{
	if (color->x_r < 0 || color->x_r > 255
		|| color->y_g < 0 || color->y_g > 255
		|| color->z_b < 0 || color->z_b > 255)
		rt_parse_exit(rt, ERR_LIMIT);
}

void	rt_parse_veclimits(t_rt *rt, t_info3 *vec)
{
	if (vec->x_r < -1 || vec->x_r > 1
		|| vec->y_g < -1 || vec->y_g > 1
		|| vec->z_b < -1 || vec->z_b > 1)
		rt_parse_exit(rt, ERR_LIMIT);
}

void	rt_parse_checks(t_rt *rt)
{
	if (rt->scn->win_x < 0 || rt->scn->win_y < 0
		|| !rt->scn->cams
		|| !rt->scn->lights
		|| !rt->scn->objs)
		rt_exit(ERR_ELEM_MISS);
}
