#include "../incs/minirt.h"

t_intersect		*rt_init_intersection()
{
	t_intersect	*intersect;

	if (!(intersect = ft_memalloc(sizeof(t_intersect))))
		return (NULL);
	intersect->solution = 0;
	if (!(intersect->pos = rt_init_vector()))
		return (NULL);
	if (!(intersect->norm = rt_init_vector()))
		return (NULL);
	if (!(intersect->diff = rt_init_vector()))
		return (NULL);
	return (intersect);
}

int				rt_clear_intersection(t_intersect **intersect,
					t_vec *pos, t_vec *norm, t_vec *diff)
{
	if (intersect)
	{
		free(pos);
		free(norm);
		free(diff);
		free(*intersect);
		*intersect = NULL;
		return (0);
	}
	return (-1);
}

t_delta			*rt_init_delta(double a, double b, double c)
{
	t_delta		*delta;

	if (!(delta = ft_memalloc(sizeof(t_delta))))
		return (NULL);
	delta->a = a;
	delta->b = b;
	delta->c = c;
	delta->delta = b * b - 4 * a * c;
	return (delta);
}
