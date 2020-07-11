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
	rt->win_H = sp->win_H;
	rt->win_W = sp->win_W;
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

t_camera		*rt_init_camera(t_vector *origin, t_vector *direction, double fov)
{
	t_camera	*camera;

	if (!(camera = ft_memalloc(sizeof(t_camera))))
		return (NULL);
	camera->origin = origin;
	camera->direction = direction;
	camera->fov = fov;
	return (camera);
}

t_color			*rt_init_color(int red, int green, int blue)
{
	t_color		*color;

	if (!(color = ft_memalloc(sizeof(t_color))))
		return (NULL);
	color->red = red;
	color->green = green;
	color->blue = blue;
	return (color);
}

t_light			*rt_init_light(t_vector *origin, double intensity)
{
	t_light		*light;

	if (!(light = ft_memalloc(sizeof(t_light))))
		return (NULL);
	light->origin = origin;
	light->intensity = intensity;
	return (light);
}

t_object		*rt_init_sphere(t_vector *origin, double radius, t_color *color)
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

t_delta			*rt_init_delta(double a, double b, double c)
{
	t_delta		*delta;

	if (!(delta = ft_memalloc(sizeof(t_delta))))
		return (NULL);
	delta->a = a;
	delta->b = b;
	delta->c = c;
	delta->delta = b * b - 4 * a * c;
	return (delta);
}

t_display			*rt_init_display(t_vector *intersect_pos,
						t_vector *intersect_norm, t_vector *diff)
{
	t_display		*display;

	if (!(display = ft_memalloc(sizeof(t_display))))
		return (NULL);
	display->i = 0;
	display->j = 0;
	display->solution = -2;
	display->intersect_pos = intersect_pos;
	display->intersect_norm = intersect_norm;
	display->diff = diff;
	display->pix_intensity = 0;
	display->sphere_x = 0;
	display->sphere_y = 0;
	display->sphere_z = 0;
	display->sphere_red = 0;
	display->sphere_green = 0;
	display->sphere_blue = 0;
	return (display);
}
