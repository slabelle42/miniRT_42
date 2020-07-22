#include "minirt.h"

double		rt_math_solution(t_delta *delta)
{
	double	solution1;
	double	solution2;
	double	solution;

	solution1 = (-delta->b - sqrt(delta->delta)) / (2 * delta->a);
	solution2 = (-delta->b + sqrt(delta->delta)) / (2 * delta->a);
	if (solution2 < 0)
		return (-1);
	if (solution1 > 0)
		solution = solution1;
	else
		solution = solution2;
	return (solution);
}

double		rt_math_dotproduct(t_vec *vec1, t_vec *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

double		rt_math_intersect(t_cams *cam, t_objs *obj)
{
	t_vec	*diff;
	t_delta	*delta;
	double	solution;

	if (!(diff = rt_init_vector()))
		exit(-1);
	diff->x = cam->ori->x - obj->ori->x;
	diff->y = cam->ori->y - obj->ori->y;
	diff->z = cam->ori->z - obj->ori->z;
	if (!(delta = rt_init_delta(1, 2 * rt_math_dotproduct(cam->dir, diff),
		rt_math_norm2(diff) - obj->size * obj->size)))
		exit(-1);
	free(diff);
	if (delta->delta < 0)
	{
		free(delta);
		return (-1);
	}
	solution = rt_math_solution(delta);
	free(delta);
	if (solution < 0)
		return (-1);
	return (solution);
}
