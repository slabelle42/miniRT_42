#include "minirt.h"

t_scn			*rt_init_scene()
{
	t_scn		*scn;

	if (!(scn = ft_memalloc(sizeof(t_scn))))
		return (NULL);
	scn->file_name = "";
	scn->win_H = 0;
	scn->win_W = 0;
	scn->cams = NULL;
	scn->lights = NULL;
	scn->objs = NULL;
	scn->mlx_ptr = NULL;
	scn->win_ptr = NULL;
	scn->img_ptr = NULL;
	scn->i = 0;
	scn->j = 0;
	scn->pix_intens = 0;
	if (!(scn->ori = rt_init_vector()))
		return (NULL);
	if (!(scn->color = rt_init_color()))
		return (NULL);
	return (scn);
}

int				rt_clear_scene(t_scn **scn,
					t_cams *cams, t_lights *lights, t_objs *objs)
{
	if (scn && cams && lights && objs)
	{
		rt_clear_cameras(&cams);
		rt_clear_lights(&lights);
		rt_clear_objects(&objs);
		free(*scn);
		*scn = NULL;
		return (0);
	}
	return (-1);
}

void			rt_clear_scene_structs(t_vec *ori, t_color *color)
{
	free(ori);
	free(color);
}
