/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct_6_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:05:15 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:05:16 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj		*rt_init_object(void)
{
	t_obj	*obj;

	if (!(obj = ft_memalloc(sizeof(t_obj))))
		rt_exit(ERR_MALLOC);
	obj->type = 'x';
	obj->ori = rt_init_info3();
	obj->vec = rt_init_info3();
	obj->size1 = 0.0;
	obj->size2 = 0.0;
	obj->color = rt_init_info3();
	obj->next = NULL;
	return (obj);
}

int			rt_add_object(t_obj **objs, t_obj *new_obj)
{
	t_obj	*tmp;

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

static void	rt_delone_object(t_obj *obj)
{
	if (obj)
	{
		free(obj->ori);
		free(obj->vec);
		free(obj->color);
		free(obj);
	}
}

void		rt_clear_objects(t_obj **objs)
{
	t_obj	*tmp;

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
