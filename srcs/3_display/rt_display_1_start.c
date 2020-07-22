#include "minirt.h"

void			rt_display_pixel(t_scn *scn, t_intersect *intersect)
{
	rt_math_pos_norm(scn, intersect);
	rt_display_getdiff(scn->lights, intersect);
	rt_display_pixintens(scn, intersect);
	mlx_pixel_put(scn->mlx_ptr, scn->win_ptr, scn->j,
		(scn->win_H - scn->i - 1), rt_display_rgbtoi(
		scn->pix_intens * scn->color->R / 255,
		scn->pix_intens * scn->color->G / 255,
		scn->pix_intens * scn->color->B / 255));
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
	while (scn->i < scn->win_H)
	{
		while (scn->j < scn->win_W)
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
	scn->mlx_ptr = mlx_init();
	scn->win_ptr = mlx_new_window(scn->mlx_ptr, scn->win_W, scn->win_H,
		scn->file_name);
	rt_display_scene(scn);
	mlx_hook(scn->win_ptr, 2, 1L << 0, rt_keys, 0);
	mlx_hook(scn->win_ptr, 17, 1L << 17, rt_keys_exit, 0);
	mlx_loop(scn->mlx_ptr);
}
