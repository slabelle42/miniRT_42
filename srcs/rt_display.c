#include "../incs/minirt.h"

int	rt_display_pixels(t_rt *rt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rt->res_W)
	{
		while (j < rt->res_H)
		{
			mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, i, j,
				rt_color_rgbtoi(rt->color_red, rt->color_green, rt->color_blue));
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	rt_display_xpm(char *xpm_file_name, t_rt *rt, int x, int y)
{
	rt->img_ptr = mlx_xpm_file_to_image(rt->mlx_ptr, xpm_file_name, &x, &y);
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, x, y);
	return (0);
}
