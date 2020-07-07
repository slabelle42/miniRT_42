#include "../incs/minirt.h"

static t_rt		*rt_init_struct(void)
{
	t_rt		*rt;

	if (!(rt = ft_memalloc(sizeof(t_rt))))
		return (NULL);
	rt->mlx_ptr = NULL;
	rt->win_ptr = NULL;
	rt->img_ptr = NULL;
	rt->win_name = "miniRT";
	rt->win_W = 640;
	rt->win_H = 640;
	return (rt);
}	

int				main(int ac, char **av)
{
	t_rt		*rt;
	int			xpm_x;
	int			xpm_y;
	t_vector	*origin;
	t_object	*sphere;

	if (!(rt = rt_init_struct()))
		return (-1);
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, rt->win_W, rt->win_H, rt->win_name);
	if (av[1])
	{
		xpm_x = 100;
		xpm_y = 100;
		rt_display_xpm(av[1], rt, xpm_x, xpm_y);
	}
	else
	{
		origin = rt_init_vector(0, 0, -55);
		sphere = rt_init_sphere(origin, 20, 65280);
		rt_display_sphere(rt, sphere);
		free(sphere);
		free(origin);
	}
	mlx_loop(rt->mlx_ptr);
	free(rt);
	return (0);
}
