#include "../incs/minirt.h"

int				rt_display_sphere(t_rt *rt, t_object *sphere)
{
	double		i;
	double		j;
	t_vector	*origin;
	t_vector	*direction;
	t_ray		*ray;
	double		fov;
	char		intersec;

	i = 0;
	j = 0;
	origin = rt_init_vector(0, 0, 0);
	direction = rt_init_vector(0, 0, 0);
	ray = rt_init_ray(origin, direction);
	fov = 60 * M_PI / 180;
	while (i < rt->win_W)
	{
		while (j < rt->win_H)
		{
			ray->direction->x = j - rt->win_W / 2;
			ray->direction->y = i - rt->win_H / 2;
			ray->direction->z = -rt->win_W / (2 * tan(fov / 2));
			rt_vector_normalize(ray->direction);
			intersec = rt_vector_intersec(ray, sphere);
			if (intersec == 'y')
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
	free(ray);
	free(direction);
	free(origin);
	return (0);
}

int				rt_display_xpm(char *xpm_file_name, t_rt *rt, int x, int y)
{
	rt->img_ptr = mlx_xpm_file_to_image(rt->mlx_ptr, xpm_file_name, &x, &y);
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, x, y);
	return (0);
}
