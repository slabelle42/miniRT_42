#include "../incs/minirt.h"

double			rt_math_solution(t_delta *delta)
{
	double		solution1;
	double		solution2;
	double		solution;

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

double			rt_math_intersect(t_camera *camera, t_objects *sphere)
{
	t_vector	*diff;
	t_delta		*delta;
	double		solution;

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
	solution = rt_math_solution(delta);
	free(delta);
	if (solution < 0)
		return (-1);
	return (solution);
}

void			rt_math_pos_norm(t_camera *camera, t_display *display)
{
	display->intersect_pos->x = camera->origin->x + display->solution
		* camera->direction->x;
	display->intersect_pos->y = camera->origin->y + display->solution
		* camera->direction->y;
	display->intersect_pos->z = camera->origin->z + display->solution
		* camera->direction->z;
	display->intersect_norm->x = display->intersect_pos->x - display->sphere_x;
	display->intersect_norm->y = display->intersect_pos->y - display->sphere_y;
	display->intersect_norm->z = display->intersect_pos->z - display->sphere_z;
	rt_math_normalize(display->intersect_norm);
}
