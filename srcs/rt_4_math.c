#include "../incs/minirt.h"

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

void			rt_math_pos_norm(t_camera *camera, t_object *sphere,
					t_display *display)
{
	display->intersect_pos->x = camera->origin->x + display->solution
		* camera->direction->x;
	display->intersect_pos->y = camera->origin->y + display->solution
		* camera->direction->y;
	display->intersect_pos->z = camera->origin->z + display->solution
		* camera->direction->z;
	display->intersect_norm->x = display->intersect_pos->x - sphere->origin->x;
	display->intersect_norm->y = display->intersect_pos->y - sphere->origin->y;
	display->intersect_norm->z = display->intersect_pos->z - sphere->origin->z;
	rt_math_normalize(intersect_norm);
}
