#include "../incs/minirt.h"

static t_simul_parse	*rt_init_sp(char *file_name)
{
	t_simul_parse		*sp;

	if (!(sp = ft_memalloc(sizeof(t_simul_parse))))
		return (NULL);
	sp->file_name = file_name;
	sp->win_H = 640;
	sp->win_W = 640;
	sp->fov = 60 * M_PI / 180;
	sp->cam_ori_x = 0;
	sp->cam_ori_y = 0;
	sp->cam_ori_z = 0;
	sp->cam_dir_x = 0;
	sp->cam_dir_y = 0;
	sp->cam_dir_z = 0;
	sp->li_ori_x = 15;
	sp->li_ori_y = 70;
	sp->li_ori_z = -30;
	sp->li_intens = 300;
	sp->obj1_type = 's';
	sp->obj1_ori_x = 0;
	sp->obj1_ori_y = 0;
	sp->obj1_ori_z = -55;
	sp->obj1_rad = 20;
	sp->obj1_R = 0;
	sp->obj1_G = 255;
	sp->obj1_B = 0;
	sp->obj2_type = 's';
	sp->obj2_ori_x = 0;
	sp->obj2_ori_y = -2000 -20;
	sp->obj2_ori_z = 0;
	sp->obj2_rad = 2000;
	sp->obj2_R = 0;
	sp->obj2_G = 0;
	sp->obj2_B = 255;
	return (sp);
}

int						main(int ac, char **av)
{
	t_simul_parse		*sp;
	t_scn				*scn;

	if (ac == 1)
	{
		if (!(sp = rt_init_sp(av[1])))
			return (-1);
		if (!(scn = rt_parse(sp)))
			return (-1);
		rt_display_window(scn);
		rt_clear_scene_structs(scn->ori, scn->color);
		rt_clear_scene(&scn, scn->cams, scn->lights, scn->objs);
		free(sp);
	}
	return (0);
}
