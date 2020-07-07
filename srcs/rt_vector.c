#include "../incs/minirt.h"

double			rt_vector_dot(t_vector *vec1, t_vector *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

char			rt_vector_intersec(t_ray *ray, t_object *sphere)
{
	double		a;
	t_vector	*diff;
	double		b;
	double		c;
	double		delta;
	double		solution1;
	double		solution2;

	a = 1;
	diff = rt_init_vector(ray->origin->x - sphere->origin->x,
		ray->origin->y - sphere->origin->y,
		ray->origin->z - sphere->origin->z);
	b = 2 * rt_vector_dot(ray->direction, diff);
	c = rt_vector_norm2(diff) - sphere->radius * sphere->radius;
	delta = b * b - 4 * a * c;
	free(diff);
	if (delta < 0)
		return ('n');
	solution1 = (-b - sqrt(delta)) / (2 * a);
	solution2 = (-b + sqrt(delta)) / (2 * a);
	if (solution2 > 0)
		return ('y');
	return ('n');
}

double			rt_vector_norm2(t_vector *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

void			rt_vector_normalize(t_vector *vec)
{
	double		norm;

	norm = sqrt(rt_vector_norm2(vec));
	vec->x /= norm;
	vec->y /= norm;
	vec->z /= norm;
}
