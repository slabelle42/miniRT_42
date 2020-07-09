#include "../incs/minirt.h"

void			rt_parse(t_simul_parse *sp)
{
	t_rt		*rt;
	t_vector	*vec_r_o;
	t_vector	*vec_r_d;
	t_ray		*ray;
	t_vector	*vec_l_o;
	t_light		*light;
	t_vector	*vec_s_o;
	t_object	*sphere;

	if (!(rt = rt_init_rt(sp)))
		exit(-1);
	if (!(vec_r_o = rt_init_vector(sp->ray_o_x, sp->ray_o_y, sp->ray_o_z)))
		exit(-1);
	if (!(vec_r_d = rt_init_vector(sp->ray_d_x, sp->ray_d_y, sp->ray_d_z)))
		exit(-1);
	if (!(ray = rt_init_ray(vec_r_o, vec_r_d)))
		exit(-1);
	if (!(vec_l_o = rt_init_vector(sp->li_o_x, sp->li_o_y, sp->li_o_z)))
		exit(-1);
	if (!(light = rt_init_light(vec_l_o, sp->li_i)))
		exit(-1);
	if (!(vec_s_o = rt_init_vector(sp->obj_o_x, sp->obj_o_y, sp->obj_o_z)))
		exit(-1);
	if (!(sphere = rt_init_sphere(vec_s_o, sp->obj_r,
		rt_color_rgbtoi(sp->obj_red, sp->obj_green, sp->obj_blue))))
		exit(-1);
	rt_display(rt, ray, light, sphere);
	free(rt);
	free(vec_r_o);
	free(vec_r_d);
	free(ray);
	free(vec_l_o);
	free(light);
	free(vec_s_o);
	free(sphere);
}
