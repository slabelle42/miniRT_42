/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:34:47 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/04 10:35:01 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rt_keys(int key, t_rt *rt)
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
			rt->loop = 0;
			if (rt->scn->cam_current == rt->scn->cam_nb)
				rt->scn->cam_current = 0;
			rt_image(rt, &rt->scn->cams, 0);
		}
	}
	return (0);
}

int		rt_quit(t_rt *rt)
{
	mlx_destroy_window(rt->mlx_ptr, rt->win_ptr);
	clear_rt(&rt, rt->scn);
	rt_exit(0);
	return (0);
}

int		rt_loop(t_rt *rt)
{
	(rt->scn->cam_current)--;
	rt_image(rt, &rt->scn->cams, 0);
	return (0);
}
