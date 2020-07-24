/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit_and_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:06:37 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:06:38 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_exit_ko_noscn(int error_nb)
{
	if (error_nb == 1)
		ft_putendl_fd("Error 1 : missing argument :'( I need a file name", 1);
	else if (error_nb == 2)
		ft_putendl_fd("Error 2 : wrong file type :'( I need a .rt file", 1);
	else if (error_nb == 3)
		ft_putendl_fd("Error 3 : wrong file name :'( I can't find it", 1);
	else
		ft_putendl_fd("Error 99 : error not specified... yet ;)", 1);
	exit(-1);
}

void	rt_exit_ko(int error_nb, t_scn *scn)
{
	rt_clear_scene(&scn, scn->cams, scn->lights, scn->objs);
	if (error_nb == 10)
		ft_putendl_fd("Error 10 : wrong parameter :'(", 1);
	else if (error_nb == 42)
		ft_putendl_fd(
			"Error 42 : technical issue, oops o_O Did we break something?", 1);
	else
		ft_putendl_fd("Error 99 : error not specified... yet ;)", 1);
	exit(-1);
}

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
