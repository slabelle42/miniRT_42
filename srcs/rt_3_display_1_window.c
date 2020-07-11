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
					t_object *s1, t_object *s2, t_display *display)
{
	double		tmp_solution;

	while (display->i < rt->win_H)
	{
		while (display->j < rt->win_W)
		{
			rt_display_adjustcam(rt, camera, display);
			display->solution = rt_math_intersect(camera, s1);
			tmp_solution = rt_math_intersect(camera, s2);
			if (display->solution > -1)
			{
				display->sphere_x = s1->origin->x;
				display->sphere_y = s1->origin->y;
				display->sphere_z = s1->origin->z;
				display->sphere_red = s1->color->red;
				display->sphere_green = s1->color->green;
				display->sphere_blue = s1->color->blue;
				if (tmp_solution < display->solution)
					if (tmp_solution > -1)
					{
						display->solution = tmp_solution;
						display->sphere_x = s2->origin->x;
						display->sphere_y = s2->origin->y;
						display->sphere_z = s2->origin->z;
						display->sphere_red = s2->color->red;
						display->sphere_green = s2->color->green;
						display->sphere_blue = s2->color->blue;
					}
				rt_display_object(rt, camera, light, display);
			}
			else if (tmp_solution > -1)
			{
				display->solution = tmp_solution;
				display->sphere_x = s2->origin->x;
				display->sphere_y = s2->origin->y;
				display->sphere_z = s2->origin->z;
				display->sphere_red = s2->color->red;
				display->sphere_green = s2->color->green;
				display->sphere_blue = s2->color->blue;
				rt_display_object(rt, camera, light, display);
			}
			else
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, display->j,
					rt->win_H - display->i - 1, rt_color_rgbtoi(0, 0, 0));
			display->j++;
		}
		display->i++;
		display->j = 0;
	}
}

void			rt_display_window(t_rt *rt, t_camera *camera, t_light *light,
					t_object *s1, t_object *s2, t_display *display)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, rt->win_W, rt->win_H,
		rt->win_name);
	rt_display_scene(rt, camera, light, s1, s2, display);
	mlx_loop(rt->mlx_ptr);
}

void			rt_display(t_rt *rt, t_camera *camera, t_light *light,
					t_object *s1, t_object *s2)
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
	rt_display_window(rt, camera, light, s1, s2, display);
	free(intersect_pos);
	free(intersect_norm);
	free(diff);
	free(display);
}
