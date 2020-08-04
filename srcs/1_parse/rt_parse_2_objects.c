/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_2_objects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:03:04 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:03:30 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			rt_parse_sphere(t_scn *scn, t_objs **objs, char *line)
{
	t_objs		*tmp;

	if (rt_add_object(objs, rt_init_object()) == -1)
		rt_exit_ko_line(ERR_MALLOC, scn, line);
	tmp = *objs;
	while (tmp->next)
		tmp = tmp->next;
	scn->i = 2;
	tmp->type = 's';
	rt_parse_move(scn, line);
	rt_parse_vector(scn, tmp->ori, line);
	rt_parse_move(scn, line);
	tmp->size = rt_parse_todouble(scn, line);
	rt_parse_move(scn, line);
	rt_parse_color(scn, tmp->color, line);
	if (tmp->color->r < 0 || tmp->color->r > 255
		|| tmp->color->g < 0 || tmp->color->g > 255
		|| tmp->color->b < 0 || tmp->color->b > 255)
		rt_exit_ko_line(ERR_LIMIT_COLOR, scn, line);
	tmp = NULL;
}
