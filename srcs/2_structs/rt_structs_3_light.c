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

static void		rt_delone_light(t_lights *lights)
{
	if (lights)
	{
		free(lights->ori);
		free(lights->color);
		free(lights);
	}
}

void			rt_clear_lights(t_lights **lights)
{
	t_lights	*tmp;

	if (lights && *lights)
	{
		while (lights && *lights)
		{
			tmp = (*lights)->next;
			rt_delone_light(*lights);
			*lights = tmp;
		}
	}
}
