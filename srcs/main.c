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
	sp->cam_o_x = 0;
	sp->cam_o_y = 0;
	sp->cam_o_z = 0;
	sp->cam_d_x = 0;
	sp->cam_d_y = 0;
	sp->cam_d_z = 0;
	sp->li_o_x = 15;
	sp->li_o_y = 70;
	sp->li_o_z = -30;
	sp->li_i = 300;
	sp->obj_o_x = 0;
	sp->obj_o_y = 0;
	sp->obj_o_z = -55;
	sp->obj_r = 20;
	sp->obj_red = 0;
	sp->obj_green = 255;
	sp->obj_blue = 0;
	return (sp);
}

int						main(int ac, char **av)
{
	t_simul_parse		*sp;

	ac *= 1;
	if (!(sp = rt_init_sp(av[1])))
		return (-1);
	rt_parse(sp);
	free(sp);
	return (0);
}
