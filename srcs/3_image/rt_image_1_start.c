/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_1_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:05:40 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:05:42 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rt_image_pixeltoimage(t_rt *rt, t_scn *scn, t_img *img,
				t_info3 *pixel_color)
{
	char	*dst;

	dst = img->addr
		+ ((scn->win_y - rt->i - 1) * img->line_length
		+ rt->j * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = rt_image_rgbtoi(pixel_color);
}

static void	rt_image_scan(t_rt *rt, t_scn *scn, t_hit *hit, t_cam *cam)
{
	t_obj	*obj_hit;
	t_info3	*pixel_color;

	rt->i = 0;
	while (rt->i < scn->win_y)
	{
		rt->j = 0;
		while (rt->j < scn->win_x)
		{
			rt_image_adjustray(rt, scn, cam, hit->ray_light);
			if ((obj_hit = rt_image_getobjhit(scn, hit)))
				pixel_color = rt_image_getcolor(scn, scn->amb, hit, obj_hit);
			else
				pixel_color = rt_init_info3();
			rt_image_pixeltoimage(rt, scn, rt->img, pixel_color);
			free(pixel_color);
			obj_hit = NULL;
			(rt->j)++;
		}
		(rt->i)++;
	}
}

static void	rt_image_init(t_rt *rt, t_scn *scn, t_img *img)
{
	int		max_x;
	int		max_y;

	rt->mlx_ptr = mlx_init();
	img->img = mlx_new_image(
		rt->mlx_ptr, scn->win_x, scn->win_y);
	img->addr = mlx_get_data_addr(
		img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	mlx_get_screen_size(
		rt->mlx_ptr, &max_x, &max_y);
	if (scn->win_x > max_x)
		scn->win_x = max_x;
	if (scn->win_y > max_y)
		scn->win_y = max_y;
}

void		rt_image(t_rt *rt, t_cam **cams, int start)
{
	t_cam	*cam;

	(rt->scn->cam_current)++;
	rt_image_init(rt, rt->scn, rt->img);
	rt->i = 1;
	cam = *cams;
	while ((rt->i)++ < rt->scn->cam_current)
		cam = cam->next;
	rt_image_scan(rt, rt->scn, rt->hit, cam);
	cam = NULL;
	if (start)
		ft_putendl_fd("done!", 1);
	rt_window(rt, rt->scn, start);
}

void		rt_window(t_rt *rt, t_scn *scn, int start)
{
	if (!rt->loop)
	{
		rt->loop = 1;
		ft_putstr_fd("--> Camera ", 1);
		ft_putnbr_fd(scn->cam_current, 1);
		ft_putendl_fd(" is displayed", 1);
	}
	if (start)
	{
		ft_putendl_fd("[ Commands: ESC = quit, C = change camera ]", 1);
		if (scn->amb->intens == 0)
			ft_putendl_fd("\n  /!\\  Ambient light intensity is 0\n", 1);
		rt->win_ptr = mlx_new_window(rt->mlx_ptr, scn->win_x, scn->win_y,
			rt->file->name);
		mlx_hook(rt->win_ptr, 2, 1L << 0, rt_keys, rt);
		mlx_hook(rt->win_ptr, 17, 1L << 17, rt_quit, rt);
		mlx_hook(rt->win_ptr, 12, 1L << 15, rt_loop, rt);
		mlx_loop(rt->mlx_ptr);
	}
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img->img, 0, 0);
	mlx_destroy_image(rt->mlx_ptr, rt->img->img);
}
