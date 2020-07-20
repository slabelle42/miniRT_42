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

t_cams			*rt_fill_camera(t_cams *cam, double fov)
{
	cam->fov = fov * M_PI / 180;
	return (cam);
}

t_cams			*rt_fill_camera_origin(t_cams *cam,
					double x, double y, double z)
{
	cam->ori->x = x;
	cam->ori->y = y;
	cam->ori->z = z;
	return (cam);
}

t_cams			*rt_fill_camera_direction(t_cams *cam,
					double x, double y, double z)
{
	cam->dir->x = x;
	cam->dir->y = y;
	cam->dir->z = z;
	return (cam);
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
