#include "minirt.h"

double		rt_math_fov(double fov)
{
	return (fov * M_PI / 180);
}

double		rt_math_norm2(t_vec *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

void		rt_math_normalize(t_vec *vec)
{
	double	norm;

	norm = sqrt(rt_math_norm2(vec));
	vec->x /= norm;
	vec->y /= norm;
	vec->z /= norm;
}

void		rt_math_pos_norm(t_scn *scn, t_intersect *intersect)
{
	intersect->pos->x = scn->cams->ori->x
		+ intersect->solution * scn->cams->dir->x;
	intersect->pos->y = scn->cams->ori->y
		+ intersect->solution * scn->cams->dir->y;
	intersect->pos->z = scn->cams->ori->z
		+ intersect->solution * scn->cams->dir->z;
	intersect->norm->x = intersect->pos->x - scn->ori->x;
	intersect->norm->y = intersect->pos->y - scn->ori->y;
	intersect->norm->z = intersect->pos->z - scn->ori->z;
	rt_math_normalize(intersect->norm);
}
