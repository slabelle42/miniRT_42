#include "../incs/minirt.h"

void		rt_display(t_rt *rt, t_ray *ray, t_object *sphere)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, rt->win_W, rt->win_H, rt->win_name);
	rt_display_sphere(rt, ray, sphere);
	mlx_loop(rt->mlx_ptr);
}

void		rt_display_sphere(t_rt *rt, t_ray *ray, t_object *sphere)
{
	double	i;
	double	j;
	char	intersect;

	i = 0;
	j = 0;
	while (i < rt->win_W)
	{
		while (j < rt->win_H)
		{
			ray->direction->x = j - rt->win_W / 2;
			ray->direction->y = i - rt->win_H / 2;
			ray->direction->z = -rt->win_W / (2 * tan(rt->fov / 2));
			rt_math_normalize(ray->direction);
			intersect = rt_math_intersect(ray, sphere);
			if (intersect == 'y')
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, i, j,
					sphere->color);
			else
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, i, j,
					rt_color_rgbtoi(0, 0, 0));
			j++;
		}
		i++;
		j = 0;
	}
}
