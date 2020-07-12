#include "../incs/minirt.h"

t_scn			*rt_parse(t_simul_parse *sp)
{
	t_cams		*cams;
	t_lights	*lights;
	t_objs		*objs;
	t_objs		*tmp;
	t_scn		*scn;

	if (!(cams = rt_init_camera()))
		return (NULL);
	rt_fill_camera(cams, sp->fov);
	rt_fill_camera_origin(cams, sp->cam_ori_x, sp->cam_ori_y, sp->cam_ori_z);
	rt_fill_camera_direction(cams, sp->cam_dir_x, sp->cam_dir_y, sp->cam_dir_z);
	if (!(lights = rt_init_light()))
		return (NULL);
	rt_fill_light(lights, sp->li_intens);
	rt_fill_light_origin(lights, sp->li_ori_x, sp->li_ori_y, sp->li_ori_z);
	if (!(objs = rt_init_object()))
		return (NULL);
	rt_fill_object(objs, sp->obj1_type, sp->obj1_rad);
	rt_fill_object_origin(objs, sp->obj1_ori_x, sp->obj1_ori_y, sp->obj1_ori_z);
	rt_fill_object_color(objs, sp->obj1_R, sp->obj1_G, sp->obj1_B);
	if (rt_add_object(&objs, rt_init_object()) == -1)
		return (NULL);
	tmp = objs;
	tmp = tmp->next;
	rt_fill_object(tmp, sp->obj2_type, sp->obj2_rad);
	rt_fill_object_origin(tmp, sp->obj2_ori_x, sp->obj2_ori_y, sp->obj2_ori_z);
	rt_fill_object_color(tmp, sp->obj2_R, sp->obj2_G, sp->obj2_B);
	tmp = NULL;
	if (!(scn = rt_init_scene()))
		return (NULL);
	rt_fill_scene_R(scn, sp->file_name, sp->win_H, sp->win_W);
	rt_fill_scene_CLO(scn, cams, lights, objs);
	return (scn);
}
