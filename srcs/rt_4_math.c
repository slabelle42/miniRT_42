#include "../incs/minirt.h"

double			rt_math_dotproduct(t_vector *vec1, t_vector *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

char			rt_math_intersect(t_ray *ray, t_object *sphere,
				t_vector *intersect_pos, t_vector *intersect_norm)
{
	double		a;
	t_vector	*diff;
	double		b;
	double		c;
	double		delta;
	double		sol1;
	double		sol2;
	double		sol;

	a = 1;
	if (!(diff = rt_init_vector(ray->origin->x - sphere->origin->x,
		ray->origin->y - sphere->origin->y,
		ray->origin->z - sphere->origin->z)))
		exit(-1);
	b = 2 * rt_math_dotproduct(ray->direction, diff);
	c = rt_math_norm2(diff) - sphere->size * sphere->size;
	delta = b * b - 4 * a * c;
	free(diff);
	if (delta < 0)
		return ('n');
	sol1 = (-b - sqrt(delta)) / (2 * a);
	sol2 = (-b + sqrt(delta)) / (2 * a);
	if (sol2 < 0)
		return ('n');
	if (sol1 > 0)
		sol = sol1;
	else
		sol = sol2;
	intersect_pos->x = ray->origin->x + sol * ray->direction->x;
	intersect_pos->y = ray->origin->y + sol * ray->direction->y;
	intersect_pos->z = ray->origin->z + sol * ray->direction->z;
	intersect_norm->x = intersect_pos->x - sphere->origin->x;
	intersect_norm->y = intersect_pos->y - sphere->origin->y;
	intersect_norm->z = intersect_pos->z - sphere->origin->z;
	rt_math_normalize(intersect_norm);
	return ('y');
}

double			rt_math_norm2(t_vector *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

void			rt_math_normalize(t_vector *vec)
{
	double		norm;

	norm = sqrt(rt_math_norm2(vec));
	vec->x /= norm;
	vec->y /= norm;
	vec->z /= norm;
}
