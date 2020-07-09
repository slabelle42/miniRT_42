#include "../incs/minirt.h"

t_rt			*rt_init_rt(t_simul_parse *sp)
{
	t_rt		*rt;

	if (!(rt = ft_memalloc(sizeof(t_rt))))
		return (NULL);
	rt->mlx_ptr = NULL;
	rt->win_ptr = NULL;
	rt->img_ptr = NULL;
	rt->win_name = sp->file_name;
	rt->win_W = sp->win_W;
	rt->win_H = sp->win_H;
	rt->fov = sp->fov;
	return (rt);
}

t_vector		*rt_init_vector(double x, double y, double z)
{
	t_vector	*vector;

	if (!(vector = ft_memalloc(sizeof(t_vector))))
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_ray			*rt_init_ray(t_vector *origin, t_vector *direction)
{
	t_ray		*ray;

	if (!(ray = ft_memalloc(sizeof(t_ray))))
		return (NULL);
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

t_object		*rt_init_sphere(t_vector *origin, double radius, int color)
{
	t_object	*sphere;

	if (!(sphere = ft_memalloc(sizeof(t_object))))
		return (NULL);
	sphere->type = 's';
	sphere->origin = origin;
	sphere->size = radius;
	sphere->color = color;
	return (sphere);
}
