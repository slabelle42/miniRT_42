/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structs_4_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:05:00 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:05:02 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objs			*rt_init_object(void)
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

static void		rt_delone_object(t_objs *objs)
{
	if (objs)
	{
		free(objs->ori);
		free(objs->color);
		free(objs);
	}
}

void			rt_clear_objects(t_objs **objs)
{
	t_objs		*tmp;

	if (objs && *objs)
	{
		while (objs && *objs)
		{
			tmp = (*objs)->next;
			rt_delone_object(*objs);
			*objs = tmp;
		}
	}
}
