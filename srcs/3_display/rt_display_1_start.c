/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_display_1_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:05:40 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:05:42 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			rt_display_pixel(t_scn *scn, t_intersect *intersect)
{
	rt_math_pos_norm(scn, intersect);
	rt_display_getdiff(scn->lights, intersect);
	rt_display_pixintens(scn, intersect);
	mlx_pixel_put(scn->mlx_ptr, scn->win_ptr, scn->j,
		(scn->win_h - scn->i - 1), rt_display_rgbtoi(
		scn->pix_intens * scn->color->r / 255,
		scn->pix_intens * scn->color->g / 255,
		scn->pix_intens * scn->color->b / 255));
}

void			rt_display_object(t_scn *scn, t_intersect *intersect)
{
	t_objs		*tmp;
	double		tmp_solution;

	tmp = scn->objs;
	intersect->solution = rt_math_intersect(scn->cams, tmp);
	if (intersect->solution > -1)
		rt_display_getobjparams(scn, tmp);
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp_solution = rt_math_intersect(scn->cams, tmp);
		if (intersect->solution < 0)
			intersect->solution = tmp_solution;
		else if (tmp_solution > -1 && tmp_solution < intersect->solution)
			intersect->solution = tmp_solution;
		if (intersect->solution > -1 && intersect->solution == tmp_solution)
			rt_display_getobjparams(scn, tmp);
	}
	if (intersect->solution > -1)
		rt_display_pixel(scn, intersect);
	tmp = NULL;
}

void			rt_display_scene(t_scn *scn)
{
	t_intersect	*intersect;

	if (!(intersect = rt_init_intersection()))
		exit(-1);
	scn->i = 0;
	scn->j = 0;
	while (scn->i < scn->win_h)
	{
		while (scn->j < scn->win_w)
		{
			rt_display_adjustcam(scn);
			rt_display_object(scn, intersect);
			scn->j++;
		}
		scn->i++;
		scn->j = 0;
	}
	rt_clear_intersection(&intersect, intersect->pos,
		intersect->norm, intersect->diff);
}

void			rt_display_window(t_scn *scn)
{
	ft_putendl_fd(
		"Parsing ended successfully, let's see what we've got here ^^", 1);
	scn->mlx_ptr = mlx_init();
	scn->win_ptr = mlx_new_window(scn->mlx_ptr, scn->win_w, scn->win_h,
		scn->file_name);
	rt_display_scene(scn);
	mlx_hook(scn->win_ptr, 2, 1L << 0, rt_keys, scn);
	mlx_hook(scn->win_ptr, 17, 1L << 17, rt_exit_ok, scn);
	mlx_loop(scn->mlx_ptr);
}
