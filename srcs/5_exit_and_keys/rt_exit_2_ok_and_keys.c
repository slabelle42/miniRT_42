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

int		rt_exit_ok(t_scn *scn)
{
	rt_clear_scene(&scn, scn->cams, scn->lights, scn->objs);
	ft_putendl_fd("Thanks for trying MiniRT :D", 1);
	exit(0);
	return (0);
}

int		rt_keys(int key, t_scn *scn)
{
	if (key == 65307 || key == 53)
		return (rt_exit_ok(scn));
	return (0);
}
