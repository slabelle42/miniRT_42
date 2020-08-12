/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct_4_camera.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:05:00 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:05:02 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam		*rt_init_camera(void)
{
	t_cam	*cam;

	if (!(cam = ft_memalloc(sizeof(t_cam))))
		rt_exit(ERR_MALLOC);
	cam->ori = rt_init_info3();
	cam->vec = rt_init_info3();
	cam->fov = 0.0;
	cam->next = NULL;
	return (cam);
}

int			rt_add_camera(t_cam **cams, t_cam *new_cam)
{
	t_cam	*tmp;

	if (cams && new_cam)
	{
		if (!(*cams))
			*cams = new_cam;
		else
		{
			tmp = *cams;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_cam;
		}
		return (0);
	}
	return (-1);
}

static void	rt_delone_camera(t_cam *cam)
{
	if (cam)
	{
		free(cam->ori);
		free(cam->vec);
		free(cam);
	}
}

void		rt_clear_cameras(t_cam **cams)
{
	t_cam	*tmp;

	if (cams && *cams)
	{
		while (cams && *cams)
		{
			tmp = (*cams)->next;
			rt_delone_camera(*cams);
			*cams = tmp;
		}
	}
}
