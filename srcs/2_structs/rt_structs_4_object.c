#include "minirt.h"

t_objs			*rt_init_object()
{
	t_objs		*obj;

	if (!(obj = ft_memalloc(sizeof(t_objs))))
		return (NULL);
	obj->type = ' ';
	if (!(obj->ori = rt_init_vector()))
		return (NULL);
	obj->size = 0;
	if (!(obj->color = rt_init_color()))
		return (NULL);
	obj->next = NULL;
	return (obj);
}

t_objs			*rt_fill_object(t_objs *obj, char type, double size)
{
	obj->type = type;
	obj->size = size;
	return (obj);
}

t_objs			*rt_fill_object_origin(t_objs *obj,
					double x, double y, double z)
{
	obj->ori->x = x;
	obj->ori->y = y;
	obj->ori->z = z;
	return (obj);
}

t_objs			*rt_fill_object_color(t_objs *obj, int R, int G, int B)
{
	obj->color->R = R;
	obj->color->G = G;
	obj->color->B = B;
	return (obj);
}

int				rt_add_object(t_objs **objs, t_objs *new_obj)
{
	t_objs		*tmp;

	if (objs && new_obj)
	{
		if (!(*objs))
			*objs = new_obj;
		else
		{
			tmp = *objs;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_obj;
		}
		return (0);
	}
	return (-1);
}

int				rt_clear_objects(t_objs **objs)
{
	t_objs		*tmp1;
	t_objs		*tmp2;

	if (objs)
	{
		tmp1 = *objs;
		while (tmp1)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
			free(tmp2->ori);
			free(tmp2->color);
			free(tmp2);
		}
		*objs = NULL;
		return (0);
	}
	return (-1);
}
