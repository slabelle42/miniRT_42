#include "minirt.h"

t_vec			*rt_init_vector()
{
	t_vec		*vec;

	if (!(vec = ft_memalloc(sizeof(t_vec))))
		return (NULL);
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
	return (vec);
}

t_color			*rt_init_color()
{
	t_color		*color;

	if (!(color = ft_memalloc(sizeof(t_color))))
		return (NULL);
	color->R = 0;
	color->G = 0;
	color->B = 0;
	return (color);
}
