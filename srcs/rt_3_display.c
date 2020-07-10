#include "../incs/minirt.h"

void			rt_display(t_rt *rt, t_ray *ray, t_light *light, t_object *sphere)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, rt->win_W, rt->win_H, rt->win_name);
	rt_display_sphere(rt, ray, light, sphere);
	mlx_loop(rt->mlx_ptr);
}

void			rt_display_sphere(t_rt *rt, t_ray *ray, t_light *light, t_object *sphere)
{
	double		i;
	double		j;
	t_vector	*intersect_pos;
	t_vector	*intersect_norm;
	char		intersect;
	t_vector	*diff;
	double		pix_intensity;

	i = 0;
	j = 0;
	if (!(intersect_pos = rt_init_vector(0, 0, 0)))
		exit(-1);
	if (!(intersect_norm = rt_init_vector(0, 0, 0)))
		exit(-1);
	while (i < rt->win_H)
	{
		while (j < rt->win_W)
		{
			ray->direction->y = i - rt->win_H / 2;
			ray->direction->x = j - rt->win_W / 2;
			ray->direction->z = -rt->win_W / (2 * tan(rt->fov / 2));
			rt_math_normalize(ray->direction);
			intersect = rt_math_intersect(ray, sphere, intersect_pos, intersect_norm);
			if (intersect == 'y')
			{
				if (!(diff = rt_init_vector(light->origin->x - intersect_pos->x,
					light->origin->y - intersect_pos->y,
					light->origin->z - intersect_pos->z)))
					exit(-1);
				rt_math_normalize(diff);
				pix_intensity = light->intensity * rt_math_dotproduct(diff, intersect_norm)
					/ rt_math_norm2(diff);
				if (pix_intensity < 0)
					pix_intensity = 0;
				else if (pix_intensity > 255)
					pix_intensity = 255;
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, rt->win_H - i - 1, rt_color_rgbtoi(
					pix_intensity * sphere->color->red / 255,
					pix_intensity * sphere->color->green / 255,
					pix_intensity * sphere->color->blue / 255));
			}
			else
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, rt->win_H - i - 1,
					rt_color_rgbtoi(0, 0, 0));
			j++;
		}
		i++;
		j = 0;
	}
	free(intersect_pos);
	free(intersect_norm);
	free(diff);
}
