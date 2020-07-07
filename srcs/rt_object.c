#include "../incs/minirt.h"

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
	sphere->type = 'S';
	sphere->origin = origin;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}
