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
	t_obj	*obj;

	if (rt_add_object(objs, rt_init_object()) < 0)
		rt_parse_exit(rt, ERR_MALLOC);
	obj = *objs;
	while (obj->next)
		obj = obj->next;
	rt->i = 2;
	obj->type = 's';
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->ori, line);
	rt_parse_move(rt, line);
	obj->size1 = rt_parse_atod(rt, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->color, line);
	rt_parse_colorlimits(rt, obj->color);
	obj = NULL;
}

void		rt_parse_plane(t_rt *rt, t_obj **objs, char *line)
{
	t_obj	*obj;

	if (rt_add_object(objs, rt_init_object()) < 0)
		rt_parse_exit(rt, ERR_MALLOC);
	obj = *objs;
	while (obj->next)
		obj = obj->next;
	rt->i = 2;
	obj->type = 'p';
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->ori, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->vec, line);
	rt_parse_veclimits(rt, obj->vec);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->color, line);
	rt_parse_colorlimits(rt, obj->color);
	obj = NULL;
}

void		rt_parse_square(t_rt *rt, t_obj **objs, char *line)
{
	t_obj	*obj;

	if (rt_add_object(objs, rt_init_object()) < 0)
		rt_parse_exit(rt, ERR_MALLOC);
	obj = *objs;
	while (obj->next)
		obj = obj->next;
	rt->i = 2;
	obj->type = 'q';
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->ori, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->vec, line);
	rt_parse_veclimits(rt, obj->vec);
	rt_parse_move(rt, line);
	obj->size1 = rt_parse_atod(rt, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->color, line);
	rt_parse_colorlimits(rt, obj->color);
	obj = NULL;
}

void		rt_parse_cylinder(t_rt *rt, t_obj **objs, char *line)
{
	t_obj	*obj;

	if (rt_add_object(objs, rt_init_object()) < 0)
		rt_parse_exit(rt, ERR_MALLOC);
	obj = *objs;
	while (obj->next)
		obj = obj->next;
	rt->i = 2;
	obj->type = 'y';
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->ori, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->vec, line);
	rt_parse_veclimits(rt, obj->vec);
	rt_parse_move(rt, line);
	obj->size1 = rt_parse_atod(rt, line);
	rt_parse_move(rt, line);
	obj->size2 = rt_parse_atod(rt, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->color, line);
	rt_parse_colorlimits(rt, obj->color);
	obj = NULL;
}

void		rt_parse_triangle(t_rt *rt, t_obj **objs, char *line)
{
	t_obj	*obj;

	if (rt_add_object(objs, rt_init_object()) < 0)
		rt_parse_exit(rt, ERR_MALLOC);
	obj = *objs;
	while (obj->next)
		obj = obj->next;
	rt->i = 2;
	obj->type = 't';
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->ori, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->vec, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->tri, line);
	rt_parse_move(rt, line);
	rt_parse_info3(rt, obj->color, line);
	rt_parse_colorlimits(rt, obj->color);
	obj = NULL;
}
