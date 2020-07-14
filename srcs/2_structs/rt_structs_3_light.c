#include "minirt.h"

t_lights		*rt_init_light()
{
	t_lights	*light;

	if (!(light = ft_memalloc(sizeof(t_lights))))
		return (NULL);
	if (!(light->ori = rt_init_vector()))
		return (NULL);
	light->intens = 0;
	if (!(light->color = rt_init_color()))
		return (NULL);
	light->next = NULL;
	return (light);
}

t_lights		*rt_fill_light(t_lights *light, double intens)
{
	light->intens = intens;
	return (light);
}

t_lights		*rt_fill_light_origin(t_lights *light,
					double x, double y, double z)
{
	light->ori->x = x;
	light->ori->y = y;
	light->ori->z = z;
	return (light);
}

t_lights		*rt_fill_light_color(t_lights *light, int R, int G, int B)
{
	light->color->R = R;
	light->color->G = G;
	light->color->B = B;
	return (light);
}

int				rt_clear_lights(t_lights **lights)
{
	t_lights	*tmp1;
	t_lights	*tmp2;

	if (lights)
	{
		tmp1 = *lights;
		while (tmp1)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
			free(tmp2->ori);
			free(tmp2->color);
			free(tmp2);
		}
		*lights = NULL;
		return (0);
	}
	return (-1);
}
