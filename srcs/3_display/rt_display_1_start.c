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

void			rt_display_pixel(t_scn *scn, t_cams *cam,
					t_intersect *intersect)
{
	if (intersect->solution > -1)
	{
		rt_math_pos_norm(scn, cam, intersect);
		rt_display_getdiff(scn->lights, intersect);
		rt_display_pixintens(scn, intersect);
		mlx_pixel_put(scn->mlx_ptr, scn->win_ptr, scn->j,
			(scn->win_h - scn->i - 1), rt_display_rgbtoi(
			scn->pix_intens * scn->color->r / 255,
			scn->pix_intens * scn->color->g / 255,
			scn->pix_intens * scn->color->b / 255));
	}
	else
		mlx_pixel_put(scn->mlx_ptr, scn->win_ptr, scn->j,
			(scn->win_h - scn->i - 1), 0);
}

void			rt_display_object(t_scn *scn, t_cams *cam,
					t_intersect *intersect)
{
	t_objs		*obj;
	double		obj_solution;

	obj = scn->objs;
	if ((intersect->solution = rt_math_intersect(cam, obj)) == -2)
		rt_exit_ko_scn(42, scn);
	if (intersect->solution > -1)
		rt_display_getobjparams(scn, obj);
	while (obj->next)
	{
		obj = obj->next;
		if ((obj_solution = rt_math_intersect(cam, obj)) == -2)
			rt_exit_ko_scn(42, scn);
		if (intersect->solution < 0)
			intersect->solution = obj_solution;
		else if (obj_solution > -1 && obj_solution < intersect->solution)
			intersect->solution = obj_solution;
		if (intersect->solution > -1 && intersect->solution == obj_solution)
			rt_display_getobjparams(scn, obj);
	}
	rt_display_pixel(scn, cam, intersect);
	obj = NULL;
}

static void		rt_display_message(t_scn *scn)
{
	ft_putstr_fd("--> Camera ", 1);
	ft_putnbr_fd(scn->cams_current, 1);
	ft_putendl_fd(" is displayed", 1);
}

void			rt_display_scene(t_scn *scn, t_cams **cams)
{
	t_intersect	*intersect;
	t_cams		*cam;

	if (!(intersect = rt_init_intersection()))
		rt_exit_ko_scn(42, scn);
	(scn->cams_current)++;
	scn->i = 1;
	cam = *cams;
	while ((scn->i)++ < scn->cams_current)
		cam = cam->next;
	scn->i = -1;
	scn->j = -1;
	while (++(scn->i) < scn->win_h)
	{
		while (++(scn->j) < scn->win_w)
		{
			rt_display_adjustcam(scn, cam);
			rt_display_object(scn, cam, intersect);
		}
		scn->j = 0;
	}
	rt_display_message(scn);
	rt_clear_intersection(&intersect, intersect->pos,
		intersect->norm, intersect->diff);
	cam = NULL;
}

void			rt_display_window(t_scn *scn)
{
	scn->win_ptr = mlx_new_window(scn->mlx_ptr, scn->win_w, scn->win_h,
		scn->file_name);
	if (scn->cams_total > 0)
	{
		rt_display_scene(scn, &scn->cams);
		ft_putendl_fd(
			"[ Commands: ESC = quit, C = change camera, H = help ]", 1);
	}
	else
	{
		ft_putstr_fd("No camera available, what a shame :p ", 1);
		ft_putendl_fd("Press ESC to quit or H for help", 1);
	}
	mlx_hook(scn->win_ptr, 2, 1L << 0, rt_keys, scn);
	mlx_hook(scn->win_ptr, 17, 1L << 17, rt_exit_ok, scn);
	mlx_loop(scn->mlx_ptr);
}
