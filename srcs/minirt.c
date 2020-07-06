#include "../incs/minirt.h"

static t_rt	*rt_init_struct(void)
{
	t_rt	*rt;

	if (!(rt = ft_memalloc(sizeof(t_rt))))
		return (NULL);
	rt->mlx_ptr = NULL;
	rt->win_ptr = NULL;
	rt->win_name = "miniRT";
	rt->img_ptr = NULL;
	rt->res_W = 150;
	rt->res_H = 150;
	rt->color_red = 255;
	rt->color_green = 0;
	rt->color_blue = 0;
	return (rt);
}	

int			main(int ac, char **av)
{
	t_rt	*rt;
	int		x;
	int		y;

	if (!(rt = rt_init_struct()))
		return (-1);
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, rt->res_W, rt->res_H, rt->win_name);
	if (av[1])
	{
		x = 50;
		y = 50;
		rt_display_xpm(av[1], rt, x, y);
	}
	else
		rt_display_pixels(rt);
	mlx_loop(rt->mlx_ptr);
	free(rt);
	return (0);
}
