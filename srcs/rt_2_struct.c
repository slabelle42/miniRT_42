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

t_color			*rt_init_color(int R, int G, int B)
{
	t_color		*color;

	if (!(color = ft_memalloc(sizeof(t_color))))
		return (NULL);
	color->R = R;
	color->G = G;
	color->B = B;
	return (color);
}

t_display			*rt_init_display(t_simul_parse *sp, t_vector *origin,
						t_color *color)
{
	t_display		*display;

	if (!(display = ft_memalloc(sizeof(t_display))))
		return (NULL);
	display->mlx_ptr = NULL;
	display->win_ptr = NULL;
	display->img_ptr = NULL;
	display->win_name = sp->file_name;
	display->win_H = sp->win_H;
	display->win_W = sp->win_W;
	display->i = 0;
	display->j = 0;
	display->pix_intensity = 0;
	display->origin = origin;
	display->color = color;
	return (display);
}

t_cameras		*rt_init_camera(t_vector *origin, t_vector *direction,
					double fov)
{
	t_cameras	*camera;

	if (!(camera = ft_memalloc(sizeof(t_cameras))))
		return (NULL);
	camera->origin = origin;
	camera->direction = direction;
	camera->fov = fov;
	camera->next = NULL;
	return (camera);
}

t_lights		*rt_init_light(t_vector *origin, double intensity)
{
	t_lights	*light;

	if (!(light = ft_memalloc(sizeof(t_lights))))
		return (NULL);
	light->origin = origin;
	light->intensity = intensity;
	light->next = NULL;
	return (light);
}

t_objects		*rt_init_object(char type, t_vector *origin, double size,
					t_color *color)
{
	t_objects	*object;

	if (!(object = ft_memalloc(sizeof(t_objects))))
		return (NULL);
	object->type = type;
	object->origin = origin;
	object->size = size;
	object->color = color;
	object->next = NULL;
	return (object);
}

int				rt_add_object(t_objects **objects, t_objects *new_object)
{
	t_objects	*tmp;

	if (objects && new_object)
	{
		if (!(*objects))
			*objects = new_object;
		else
		{
			tmp = *objects;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_object;
		}
		return (0);
	}
	return (-1);
}

int				rt_clear_objects(t_objects **objects)
{
	t_objects	*tmp1;
	t_objects	*tmp2;

	if (objects)
	{
		tmp1 = *objects;
		while (tmp1)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
			free(tmp2->origin);
			free(tmp2->color);
			free(tmp2);
		}
		*objects = NULL;
		return (0);
	}
	return (-1);
}

t_intersection		*rt_init_intersection(t_vector *position, t_vector *normal,
						t_vector *diff)
{
	t_intersection	*intersection;

	if (!(intersection = ft_memalloc(sizeof(t_intersection))))
		return (NULL);
	intersection->solution = 0;
	intersection->position = position;
	intersection->normal = normal;
	intersection->diff = diff;
	return (intersection);
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
