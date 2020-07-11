#include "../incs/minirt.h"

void				rt_display_object(t_display *display, t_cameras *cameras,
						t_lights *lights, t_intersection *intersection)
{
	rt_math_pos_norm(display, cameras, intersection);
	if (intersection->solution > -1)
	{
		rt_display_getdiff(lights, intersection);
		rt_display_pixintens(display, lights, intersection);
		mlx_pixel_put(display->mlx_ptr, display->win_ptr, display->j,
			display->win_H - display->i - 1, rt_color_rgbtoi(
			display->pix_intensity * display->color->R / 255,
			display->pix_intensity * display->color->G / 255,
			display->pix_intensity * display->color->B / 255));
	}
}

void				rt_display_scene(t_display *display, t_cameras *cameras,
						t_lights *lights, t_objects *objects,
						t_intersection *intersection)
{
	t_objects		*tmp1;
	t_objects		*tmp2;
	double			tmp_solution;

	while (display->i < display->win_H)
	{
		while (display->j < display->win_W)
		{
			tmp1 = objects;
			tmp2 = objects;
			rt_display_adjustcam(display, cameras);
			intersection->solution = rt_math_intersect(cameras, tmp1);
			tmp1 = tmp1->next;
			tmp_solution = rt_math_intersect(cameras, tmp1);
			if (intersection->solution > -1)
			{
				rt_display_getobjparams(display, tmp2);
				if (tmp_solution < intersection->solution)
					if (tmp_solution > -1)
					{
						intersection->solution = tmp_solution;
						tmp2 = tmp2->next;
						rt_display_getobjparams(display, tmp2);
					}
				rt_display_object(display, cameras, lights, intersection);
			}
			else if (tmp_solution > -1)
			{
				intersection->solution = tmp_solution;
				tmp2 = tmp2->next;
				rt_display_getobjparams(display, tmp2);
				rt_display_object(display, cameras, lights, intersection);
			}
			else
				mlx_pixel_put(display->mlx_ptr, display->win_ptr, display->j,
					display->win_H - display->i - 1, rt_color_rgbtoi(0, 0, 0));
			tmp1 = NULL;
			tmp2 = NULL;
			display->j++;
		}
		display->i++;
		display->j = 0;
	}
}

void				rt_display_window(t_display *display, t_cameras *cameras,
						t_lights *lights, t_objects *objects,
						t_intersection *intersection)
{
	display->mlx_ptr = mlx_init();
	display->win_ptr = mlx_new_window(display->mlx_ptr, display->win_W,
		display->win_H, display->win_name);
	rt_display_scene(display, cameras, lights, objects, intersection);
	mlx_loop(display->mlx_ptr);
}

void				rt_display(t_display *display, t_cameras *cameras,
						t_lights *lights, t_objects *objects)
{
	t_vector		*position;
	t_vector		*normal;
	t_vector		*diff;
	t_intersection	*intersection;

	if (!(position = rt_init_vector(0, 0, 0)))
		exit(-1);
	if (!(normal = rt_init_vector(0, 0, 0)))
		exit(-1);
	if (!(diff = rt_init_vector(0, 0, 0)))
		exit(-1);
	if (!(intersection = rt_init_intersection(position, normal, diff)))
		exit(-1);
	rt_display_window(display, cameras, lights, objects, intersection);
	free(position);
	free(normal);
	free(diff);
	free(intersection);
}
