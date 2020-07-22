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
