/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:34:47 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/04 10:35:01 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		rt_hook(t_rt *rt)
{
	mlx_hook(rt->win_ptr, 2, 1L << 0, rt_keys, rt);
	mlx_hook(rt->win_ptr, 17, 1L << 17, rt_quit, rt);
	mlx_hook(rt->win_ptr, 12, 1L << 15, rt_loop, rt);
	mlx_loop(rt->mlx_ptr);
}

int			rt_keys(int key, t_rt *rt)
{
	if (key == KEYLINUX_ESC || key == KEYMAC_ESC)
		return (rt_quit(rt));
	if (key == KEYLINUX_C || key == KEYMAC_C)
	{
		if (rt->scn->cam_nb == 1)
		{
			ft_putstr_fd("Only 1 camera available, ", 1);
			ft_putendl_fd("try to add some more next time ;)", 1);
		}
		else if (rt->scn->cam_nb > 1)
		{
			if (rt->img->img)
				mlx_destroy_image(rt->mlx_ptr, rt->img->img);
			(rt->scn->cam_current)++;
			if (rt->scn->cam_current > rt->scn->cam_nb)
				rt->scn->cam_current = 1;
			rt_image(rt, &rt->scn->cams, 0);
		}
	}
	return (0);
}

int			rt_quit(t_rt *rt)
{
	if (rt->img->img)
		mlx_destroy_image(rt->mlx_ptr, rt->img->img);
	if (rt->win_ptr)
		mlx_destroy_window(rt->mlx_ptr, rt->win_ptr);
	free(rt->mlx_ptr);
	clear_rt(&rt, rt->scn);
	rt_exit(0);
	return (0);
}

int			rt_loop(t_rt *rt)
{
	if (rt->img->img)
		mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img->img, 0, 0);
	mlx_hook(rt->win_ptr, 12, 1L << 15, rt_loop, rt);
	return (0);
}
