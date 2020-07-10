#include "../incs/minirt.h"

void			rt_display_adjustcam(t_rt *rt, t_camera *camera,
					t_display *display)
{
	camera->direction->y = display->i - rt->win_H / 2;
	camera->direction->x = display->j - rt->win_W / 2;
	camera->direction->z = -rt->win_W / (2 * tan(camera->fov / 2));
	rt_math_normalize(camera->direction);
}

void			rt_display_getdiff(t_light *light, t_display *display)
{
	display->diff->x = light->origin->x - display->intersect_pos->x;
	display->diff->y = light->origin->y - display->intersect_pos->y;
	display->diff->z = light->origin->z - display->intersect_pos->z;
	rt_math_normalize(display->diff);
}

void			rt_display_pixintens(t_light *light, t_display *display)
{
	display->pix_intensity = light->intensity
		* rt_math_dotproduct(display->diff, display->intersect_norm)
		/ rt_math_norm2(display->diff);
	if (display->pix_intensity < 0)
		display->pix_intensity = 0;
	else if (display->pix_intensity > 255)
		display->pix_intensity = 255;
}
