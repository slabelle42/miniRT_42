#include "minirt.h"

t_cams			*rt_init_camera()
{
	t_cams		*cam;

	if (!(cam = ft_memalloc(sizeof(t_cams))))
		return (NULL);
	if (!(cam->ori = rt_init_vector()))
		return (NULL);
	if (!(cam->dir = rt_init_vector()))
		return (NULL);
	cam->fov = 0;
	cam->next = NULL;
	return (cam);
}

int				rt_add_camera(t_cams **cams, t_cams *new_cam)
{
	t_cams		*tmp;

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

static void		rt_delone_camera(t_cams *cams)
{
	if (cams)
	{
		free(cams->ori);
		free(cams->dir);
		free(cams);
	}
}

void			rt_clear_cameras(t_cams **cams)
{
	t_cams		*tmp;

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
