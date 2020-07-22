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

int				rt_add_light(t_lights **lights, t_lights *new_light)
{
	t_lights	*tmp;

	if (lights && new_light)
	{
		if (!(*lights))
			*lights = new_light;
		else
		{
			tmp = *lights;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_light;
		}
		return (0);
	}
	return (-1);
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
