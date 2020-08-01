/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_display_2_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:05:51 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:05:52 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_display_adjustcam(t_scn *scn, t_cams *cam)
{
	cam->dir->y = scn->i - scn->win_h / 2;
	cam->dir->x = scn->j - scn->win_w / 2;
	cam->dir->z = -scn->win_w / (2 * tan(cam->fov / 2));
	rt_math_normalize(cam->dir);
}

void	rt_display_getobjparams(t_scn *scn, t_objs *obj)
{
	scn->ori->x = obj->ori->x;
	scn->ori->y = obj->ori->y;
	scn->ori->z = obj->ori->z;
	scn->color->r = obj->color->r;
	scn->color->g = obj->color->g;
	scn->color->b = obj->color->b;
}

void	rt_display_getdiff(t_lights *light, t_intersect *intersect)
{
	intersect->diff->x = light->ori->x - intersect->pos->x;
	intersect->diff->y = light->ori->y - intersect->pos->y;
	intersect->diff->z = light->ori->z - intersect->pos->z;
	rt_math_normalize(intersect->diff);
}

void	rt_display_pixintens(t_scn *scn, t_intersect *intersect)
{
	scn->pix_intens = scn->lights->intens
		* rt_math_dotproduct(intersect->diff, intersect->norm)
		/ rt_math_norm2(intersect->diff);
	if (scn->pix_intens < 0)
		scn->pix_intens = 0;
	else if (scn->pix_intens > 255)
		scn->pix_intens = 255;
}

int		rt_display_rgbtoi(int r, int g, int b)
{
	return (65536 * r + 256 * g + b);
}
