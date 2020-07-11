#include "../incs/minirt.h"

void			rt_display_object(t_rt *rt, t_camera *camera, t_light *light,
					t_display *display)
{
	rt_math_pos_norm(camera, display);
	if (display->solution > -1)
	{
		rt_display_getdiff(light, display);
		rt_display_pixintens(light, display);
		mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, display->j,
			rt->win_H - display->i - 1, rt_color_rgbtoi(
			display->pix_intensity * display->sphere_red / 255,
			display->pix_intensity * display->sphere_green / 255,
			display->pix_intensity * display->sphere_blue / 255));
	}
}

void			rt_display_scene(t_rt *rt, t_camera *camera, t_light *light,
					t_objects *objects, t_display *display)
{
	t_objects	*tmp1;
	t_objects	*tmp2;
	double		tmp_solution;

	while (display->i < rt->win_H)
	{
		while (display->j < rt->win_W)
		{
			tmp1 = objects;
			tmp2 = objects;
			rt_display_adjustcam(rt, camera, display);
			display->solution = rt_math_intersect(camera, tmp1);
			tmp1 = tmp1->next;
			tmp_solution = rt_math_intersect(camera, tmp1);
			if (display->solution > -1)
			{
				display->sphere_x = tmp2->origin->x;
				display->sphere_y = tmp2->origin->y;
				display->sphere_z = tmp2->origin->z;
				display->sphere_red = tmp2->color->red;
				display->sphere_green = tmp2->color->green;
				display->sphere_blue = tmp2->color->blue;
				if (tmp_solution < display->solution)
					if (tmp_solution > -1)
					{
						display->solution = tmp_solution;
						tmp2 = tmp2->next;
						display->sphere_x = tmp2->origin->x;
						display->sphere_y = tmp2->origin->y;
						display->sphere_z = tmp2->origin->z;
						display->sphere_red = tmp2->color->red;
						display->sphere_green = tmp2->color->green;
						display->sphere_blue = tmp2->color->blue;
					}
				rt_display_object(rt, camera, light, display);
			}
			else if (tmp_solution > -1)
			{
				display->solution = tmp_solution;
				tmp2 = tmp2->next;
				display->sphere_x = tmp2->origin->x;
				display->sphere_y = tmp2->origin->y;
				display->sphere_z = tmp2->origin->z;
				display->sphere_red = tmp2->color->red;
				display->sphere_green = tmp2->color->green;
				display->sphere_blue = tmp2->color->blue;
				rt_display_object(rt, camera, light, display);
			}
			else
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, display->j,
					rt->win_H - display->i - 1, rt_color_rgbtoi(0, 0, 0));
			tmp1 = NULL;
			tmp2 = NULL;
			display->j++;
		}
		display->i++;
		display->j = 0;
	}
}

void			rt_display_window(t_rt *rt, t_camera *camera, t_light *light,
					t_objects *objects, t_display *display)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, rt->win_W, rt->win_H,
		rt->win_name);
	rt_display_scene(rt, camera, light, objects, display);
	mlx_loop(rt->mlx_ptr);
}

void			rt_display(t_rt *rt, t_camera *camera, t_light *light,
					t_objects *objects)
{
	t_vector	*intersect_pos;
	t_vector	*intersect_norm;
	t_vector	*diff;
	t_display	*display;

	if (!(intersect_pos = rt_init_vector(0, 0, 0)))
		exit(-1);
	if (!(intersect_norm = rt_init_vector(0, 0, 0)))
		exit(-1);
	if (!(diff = rt_init_vector(0, 0, 0)))
		exit(-1);
	if (!(display = rt_init_display(intersect_pos, intersect_norm, diff)))
		exit(-1);
	rt_display_window(rt, camera, light, objects, display);
	free(intersect_pos);
	free(intersect_norm);
	free(diff);
	free(display);
}
