#include "../incs/minirt.h"

void			rt_display_scene(t_rt *rt, t_camera *camera, t_light *light,
					t_object *sphere, t_display *display)
{
	while (display->i < rt->win_H)
	{
		while (display->j < rt->win_W)
		{
			rt_display_adjustcam(rt, camera, display);
			display->solution = rt_math_intersect(camera, sphere);
			rt_math_pos_norm(camera, sphere, display);
			if (display->solution >= 0)
			{
				rt_display_getdiff(light, display);
				rt_display_pixintens(light, display);
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, display->j,
					rt->win_H - display->i - 1, rt_color_rgbtoi(
					display->pix_intensity * sphere->color->red / 255,
					display->pix_intensity * sphere->color->green / 255,
					display->pix_intensity * sphere->color->blue / 255));
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
					t_object *sphere, t_display *display)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, rt->win_W, rt->win_H,
		rt->win_name);
	rt_display_scene(rt, camera, light, sphere, display);
	mlx_loop(rt->mlx_ptr);
}

void			rt_display(t_rt *rt, t_camera *camera, t_light *light,
					t_object *sphere)
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
	rt_display_window(rt, camera, light, sphere, display);
	free(intersect_pos);
	free(intersect_norm);
	free(diff);
	free(display);
}
