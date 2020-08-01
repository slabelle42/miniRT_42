/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_display_2_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 17:53:37 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/01 17:53:41 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_display_message(t_scn *scn)
{
	scn->loop = 1;
	ft_putstr_fd("--> Camera ", 1);
	ft_putnbr_fd(scn->cams_current, 1);
	ft_putendl_fd(" is displayed", 1);
}

int		rt_display_loop(t_scn *scn)
{
	(scn->cams_current)--;
	rt_display_scene(scn, &scn->cams);
	return (0);
}
