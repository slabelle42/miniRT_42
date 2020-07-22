#include "minirt.h"

t_cams			*rt_init_camera()
{
	t_cams	*cam;

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

int				rt_clear_cameras(t_cams **cams)
{
	t_cams		*tmp1;
	t_cams		*tmp2;

	if (cams)
	{
		tmp1 = *cams;
		while (tmp1)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
			free(tmp2->ori);
			free(tmp2->dir);
			free(tmp2);
		}
		*cams = NULL;
		return (0);
	}
	return (-1);
}
