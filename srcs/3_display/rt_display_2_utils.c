#include "../incs/minirt.h"

void	rt_display_adjustcam(t_scn *scn)
{
	scn->cams->dir->y = scn->i - scn->win_H / 2;
	scn->cams->dir->x = scn->j - scn->win_W / 2;
	scn->cams->dir->z = -scn->win_W / (2 * tan(scn->cams->fov / 2));
	rt_math_normalize(scn->cams->dir);
}

void	rt_display_getobjparams(t_scn *scn, t_objs *obj)
{
	scn->ori->x = obj->ori->x;
	scn->ori->y = obj->ori->y;
	scn->ori->z = obj->ori->z;
	scn->color->R = obj->color->R;
	scn->color->G = obj->color->G;
	scn->color->B = obj->color->B;
}

void	rt_display_getdiff(t_lights *light, t_intersect *intersect)
{
	intersect->diff->x = light->ori->x - intersect->pos->x;
	intersect->diff->y = light->ori->y - intersect->pos->y;
	intersect->diff->z = light->ori->z - intersect->pos->z;
	rt_math_normalize(intersect->diff);
}

void	rt_display_pixintens(t_scn *scn, t_intersect *intersect)
{
	scn->pix_intens = scn->lights->intens
		* rt_math_dotproduct(intersect->diff, intersect->norm)
		/ rt_math_norm2(intersect->diff);
	if (scn->pix_intens < 0)
		scn->pix_intens = 0;
	else if (scn->pix_intens > 255)
		scn->pix_intens = 255;
}
