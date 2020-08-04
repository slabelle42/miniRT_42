/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit_3_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:34:47 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/04 10:35:01 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
			rt_display_image(scn);
		}
	}
	return (0);
}
