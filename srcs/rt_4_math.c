#include "../incs/minirt.h"

void			rt_math_pos_norm(t_camera *camera, t_object *sphere,
					t_vector *intersect_pos, t_vector *intersect_norm,
					double sol)
{
	intersect_pos->x = camera->origin->x + sol * camera->direction->x;
	intersect_pos->y = camera->origin->y + sol * camera->direction->y;
	intersect_pos->z = camera->origin->z + sol * camera->direction->z;
	intersect_norm->x = intersect_pos->x - sphere->origin->x;
	intersect_norm->y = intersect_pos->y - sphere->origin->y;
	intersect_norm->z = intersect_pos->z - sphere->origin->z;
	rt_math_normalize(intersect_norm);
}

double			rt_math_solution(t_delta *delta)
{
	double		sol1;
	double		sol2;
	double		sol;

	sol1 = (-delta->b - sqrt(delta->delta)) / (2 * delta->a);
	sol2 = (-delta->b + sqrt(delta->delta)) / (2 * delta->a);
	if (sol2 < 0)
		return (-1);
	if (sol1 > 0)
		sol = sol1;
	else
		sol = sol2;
	return (sol);
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

double			rt_math_dotproduct(t_vector *vec1, t_vector *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

double			rt_math_intersect(t_camera *camera, t_object *sphere)
{
	t_vector	*diff;
	t_delta		*delta;
	double		sol;

	if (!(diff = rt_init_vector(camera->origin->x - sphere->origin->x,
		camera->origin->y - sphere->origin->y,
		camera->origin->z - sphere->origin->z)))
		exit(-1);
	if (!(delta = rt_init_delta(1, 2 * rt_math_dotproduct(camera->direction, diff),
		rt_math_norm2(diff) - sphere->size * sphere->size)))
		exit(-1);
	free(diff);
	if (delta->delta < 0)
	{
		free(delta);
		return (-1);
	}
	sol = rt_math_solution(delta);
	free(delta);
	if (sol < 0)
		return (-1);
	return (sol);
}
