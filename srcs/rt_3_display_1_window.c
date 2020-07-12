#include "../incs/minirt.h"

void			rt_display_object(t_scn *scn, t_intersect *intersect)
{
	rt_math_pos_norm(scn, intersect);
	if (intersect->solution > -1)
	{
		rt_display_getdiff(scn->lights, intersect);
		rt_display_pixintens(scn, intersect);
		mlx_pixel_put(scn->mlx_ptr, scn->win_ptr, scn->j,
			scn->win_H - scn->i - 1, rt_color_rgbtoi(
			scn->pix_intens * scn->color->R / 255,
			scn->pix_intens * scn->color->G / 255,
			scn->pix_intens * scn->color->B / 255));
	}
}

void			rt_display_scene(t_scn *scn)
{
	t_intersect	*intersect;
	t_objs		*tmp1;
	t_objs		*tmp2;
	double		tmp_solution;

	if (!(intersect = rt_init_intersection()))
		exit(-1);
	while (scn->i < scn->win_H)
	{
		while (scn->j < scn->win_W)
		{
			tmp1 = scn->objs;
			tmp2 = scn->objs;
			rt_display_adjustcam(scn);
			intersect->solution = rt_math_intersect(scn->cams, tmp1);
			tmp1 = tmp1->next;
			tmp_solution = rt_math_intersect(scn->cams, tmp1);
			if (intersect->solution > -1)
			{
				rt_display_getobjparams(scn, tmp2);
				if (tmp_solution < intersect->solution)
					if (tmp_solution > -1)
					{
						intersect->solution = tmp_solution;
						tmp2 = tmp2->next;
						rt_display_getobjparams(scn, tmp2);
					}
				rt_display_object(scn, intersect);
			}
			else if (tmp_solution > -1)
			{
				intersect->solution = tmp_solution;
				tmp2 = tmp2->next;
				rt_display_getobjparams(scn, tmp2);
				rt_display_object(scn, intersect);
			}
			else
				mlx_pixel_put(scn->mlx_ptr, scn->win_ptr, scn->j,
					scn->win_H - scn->i - 1, rt_color_rgbtoi(0, 0, 0));
			tmp1 = NULL;
			tmp2 = NULL;
			scn->j++;
		}
		scn->i++;
		scn->j = 0;
	}
	rt_clear_intersection(&intersect,
		intersect->pos, intersect->norm, intersect->diff);
}

void			rt_display_window(t_scn *scn)
{
	scn->mlx_ptr = mlx_init();
	scn->win_ptr = mlx_new_window(scn->mlx_ptr, scn->win_W, scn->win_H,
		scn->file_name);
	rt_display_scene(scn);
	mlx_loop(scn->mlx_ptr);
}
