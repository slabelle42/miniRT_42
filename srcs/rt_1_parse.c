#include "../incs/minirt.h"

void			rt_parse(t_simul_parse *sp)
{
	t_rt		*rt;
	t_vector	*vec_r_o;
	t_vector	*vec_r_d;
	t_camera	*camera;
	t_vector	*vec_l_o;
	t_light		*light;
	t_vector	*vec_s_o;
	t_color		*color_s;
	t_object	*sphere;

	if (!(rt = rt_init_rt(sp)))
		exit(-1);
	if (!(vec_r_o = rt_init_vector(sp->cam_o_x, sp->cam_o_y, sp->cam_o_z)))
		exit(-1);
	if (!(vec_r_d = rt_init_vector(sp->cam_d_x, sp->cam_d_y, sp->cam_d_z)))
		exit(-1);
	if (!(camera = rt_init_camera(vec_r_o, vec_r_d, sp->fov)))
		exit(-1);
	if (!(vec_l_o = rt_init_vector(sp->li_o_x, sp->li_o_y, sp->li_o_z)))
		exit(-1);
	if (!(light = rt_init_light(vec_l_o, sp->li_i)))
		exit(-1);
	if (!(vec_s_o = rt_init_vector(sp->obj_o_x, sp->obj_o_y, sp->obj_o_z)))
		exit(-1);
	if (!(color_s = rt_init_color(sp->obj_red, sp->obj_green, sp->obj_blue)))
		exit(-1);
	if (!(sphere = rt_init_sphere(vec_s_o, sp->obj_r, color_s)))
		exit(-1);
	rt_display(rt, camera, light, sphere);
	free(rt);
	free(vec_r_o);
	free(vec_r_d);
	free(camera);
	free(vec_l_o);
	free(light);
	free(vec_s_o);
	free(color_s);
	free(sphere);
}
