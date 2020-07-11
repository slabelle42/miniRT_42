#include "../incs/minirt.h"

void			rt_display_adjustcam(t_display *display, t_cameras *camera)
{
	camera->direction->y = display->i - display->win_H / 2;
	camera->direction->x = display->j - display->win_W / 2;
	camera->direction->z = -display->win_W / (2 * tan(camera->fov / 2));
	rt_math_normalize(camera->direction);
}

void			rt_display_getobjparams(t_display *display,
					t_objects *object)
{
	display->origin->x = object->origin->x;
	display->origin->y = object->origin->y;
	display->origin->z = object->origin->z;
	display->color->R = object->color->R;
	display->color->G = object->color->G;
	display->color->B = object->color->B;
}

void			rt_display_getdiff(t_lights *light,
					t_intersection *intersection)
{
	intersection->diff->x = light->origin->x - intersection->position->x;
	intersection->diff->y = light->origin->y - intersection->position->y;
	intersection->diff->z = light->origin->z - intersection->position->z;
	rt_math_normalize(intersection->diff);
}

void			rt_display_pixintens(t_display *display, t_lights *light,
					t_intersection *intersection)
{
	display->pix_intensity = light->intensity
		* rt_math_dotproduct(intersection->diff, intersection->normal)
		/ rt_math_norm2(intersection->diff);
	if (display->pix_intensity < 0)
		display->pix_intensity = 0;
	else if (display->pix_intensity > 255)
		display->pix_intensity = 255;
}
