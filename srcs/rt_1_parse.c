#include "../incs/minirt.h"

void			rt_parse(t_simul_parse *sp)
{
	t_vector	*d_vec;
	t_color		*d_color;
	t_display	*display;
	t_vector	*cam_ori;
	t_vector	*cam_dir;
	t_cameras	*cameras;
	t_vector	*li_ori;
	t_lights	*lights;
	t_vector	*obj1_ori;
	t_color		*obj1_color;
	t_vector	*obj2_ori;
	t_color		*obj2_color;
	t_objects	*objects;

	if (!(d_vec = rt_init_vector(0, 0, 0)))
		exit(-1);
	if (!(d_color = rt_init_color(0, 0, 0)))
		exit(-1);
	if (!(display = rt_init_display(sp, d_vec, d_color)))
		exit(-1);
	if (!(cam_ori = rt_init_vector(sp->cam_ori_x, sp->cam_ori_y, sp->cam_ori_z)))
		exit(-1);
	if (!(cam_dir = rt_init_vector(sp->cam_dir_x, sp->cam_dir_y, sp->cam_dir_z)))
		exit(-1);
	if (!(cameras = rt_init_camera(cam_ori, cam_dir, sp->fov)))
		exit(-1);
	if (!(li_ori = rt_init_vector(sp->li_ori_x, sp->li_ori_y, sp->li_ori_z)))
		exit(-1);
	if (!(lights = rt_init_light(li_ori, sp->li_intensity)))
		exit(-1);
	if (!(obj1_ori = rt_init_vector(sp->obj1_ori_x, sp->obj1_ori_y, sp->obj1_ori_z)))
		exit(-1);
	if (!(obj1_color = rt_init_color(sp->obj1_R, sp->obj1_G, sp->obj1_B)))
		exit(-1);
	if (!(obj2_ori = rt_init_vector(sp->obj2_ori_x, sp->obj2_ori_y, sp->obj2_ori_z)))
		exit(-1);
	if (!(obj2_color = rt_init_color(sp->obj2_R, sp->obj2_G, sp->obj2_B)))
		exit(-1);
	if (!(objects = rt_init_object(sp->obj1_type, obj1_ori, sp->obj1_rad, obj1_color)))
		exit(-1);
	if (rt_add_object(&objects, rt_init_object(sp->obj2_type, obj2_ori, sp->obj2_rad,
		obj2_color)) == -1)
		exit(-1);
	rt_display(display, cameras, lights, objects);
	free(d_vec);
	free(d_color);
	free(display);
	free(cam_ori);
	free(cam_dir);
	free(cameras);
	free(li_ori);
	free(lights);
	free(obj1_ori);
	free(obj1_color);
	free(obj2_ori);
	free(obj2_color);
	rt_clear_objects(&objects);
}
