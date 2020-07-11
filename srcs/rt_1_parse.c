#include "../incs/minirt.h"

void			rt_parse(t_simul_parse *sp)
{
	t_rt		*rt;
	t_vector	*vec_r_o;
	t_vector	*vec_r_d;
	t_camera	*camera;
	t_vector	*vec_l_o;
	t_light		*light;
	t_vector	*vec_s1_o;
	t_color		*color_s1;
	t_vector	*vec_s2_o;
	t_color		*color_s2;
	t_objects	*objects;

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
	if (!(vec_s1_o = rt_init_vector(sp->s1_o_x, sp->s1_o_y, sp->s1_o_z)))
		exit(-1);
	if (!(color_s1 = rt_init_color(sp->s1_red, sp->s1_green, sp->s1_blue)))
		exit(-1);
	if (!(vec_s2_o = rt_init_vector(sp->s2_o_x, sp->s2_o_y, sp->s2_o_z)))
		exit(-1);
	if (!(color_s2 = rt_init_color(sp->s2_red, sp->s2_green, sp->s2_blue)))
		exit(-1);
	if (!(objects = rt_init_object(sp->s1_type, vec_s1_o, sp->s1_r, color_s1)))
		exit(-1);
	if (rt_add_object(&objects, rt_init_object(sp->s2_type, vec_s2_o, sp->s2_r,
		color_s2)) == -1)
		exit(-1);
	rt_display(rt, camera, light, objects);
	free(rt);
	free(vec_r_o);
	free(vec_r_d);
	free(camera);
	free(vec_l_o);
	free(light);
	free(vec_s1_o);
	free(color_s1);
	free(vec_s2_o);
	free(color_s2);
	rt_clear_objects(&objects);
}
