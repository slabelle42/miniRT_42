/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_3_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:03:04 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:03:30 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		rt_parse_sphere(t_rt *rt, t_obj **objs, char *line)
{
	t_obj	*tmp;

	if (rt_add_object(objs, rt_init_object()) < 0)
		rt_parse_exit(rt, ERR_MALLOC);
	tmp = *objs;
	while (tmp->next)
		tmp = tmp->next;
	rt->i = 2;
	tmp->type = 's';
	rt_parse_move(rt, line);
	rt_parse_info3(rt, tmp->ori, line);
	rt_parse_move(rt, line);
	tmp->size1 = rt_parse_atod(rt, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, tmp->color, line);
	if (tmp->color->x_r < 0 || tmp->color->x_r > 255
		|| tmp->color->y_g < 0 || tmp->color->y_g > 255
		|| tmp->color->z_b < 0 || tmp->color->z_b > 255)
		rt_parse_exit(rt, ERR_LIMIT);
	tmp = NULL;
}
