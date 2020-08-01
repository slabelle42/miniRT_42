/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit_2_ok_and_keys.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:49:12 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/28 20:49:13 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			rt_exit_ok(t_scn *scn)
{
	rt_clear_scene(&scn, scn->cams, scn->lights, scn->objs);
	ft_putendl_fd("Thanks for trying MiniRT :D", 1);
	exit(0);
	return (0);
}

static void	rt_keys_help(void)
{
	ft_putendl_fd("Sure, here's a minimalist example of .rt file", 1);
	ft_putendl_fd("Use it as a basis to create new awesome scenes! ;)", 1);
	ft_putendl_fd("..", 1);
	ft_putendl_fd("R\t640\t640", 1);
	ft_putendl_fd("A\t0.5\t\t\t\t\t\t255,255,255", 1);
	ft_putendl_fd("c\t0,0,0\t\t0,0,0\t\t60", 1);
	ft_putendl_fd("l\t15,70,-30\t\t\t0.3\t\t255,255,255", 1);
	ft_putendl_fd("sp\t0,0,-55\t\t\t\t20\t\t0,255,0", 1);
	ft_putendl_fd("..", 1);
}

int			rt_keys(int key, t_scn *scn)
{
	if (key == KEY_LNX_ESC || key == KEY_MAC_ESC)
		return (rt_exit_ok(scn));
	if (key == KEY_LNX_C || key == KEY_MAC_C)
	{
		if (scn->cams_total == 1)
		{
			ft_putstr_fd("Only 1 camera available, ", 1);
			ft_putendl_fd("try to add some more next time ;)", 1);
		}
		else if (scn->cams_total > 1)
		{
			scn->loop = 0;
			if (scn->cams_current == scn->cams_total)
				scn->cams_current = 0;
			rt_display_scene(scn, &scn->cams);
		}
	}
	if (key == KEY_LNX_H || key == KEY_MAC_H)
		rt_keys_help();
	return (0);
}
