/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit_1_ko.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:06:37 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:06:38 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rt_exit_ko_twenty(int error_nb)
{
	if (error_nb == 20)
		ft_putendl_fd(
			"Error 20: ambiant light ratio limits are [0.0,1.0] :o", 1);
	else if (error_nb == 21)
		ft_putendl_fd("Error 21: camera fov limits are [0,180] :o", 1);
	else if (error_nb == 22)
		ft_putendl_fd("Error 22: light ratio limits are [0.0,1.0] :o", 1);
	else if (error_nb == 23)
		ft_putendl_fd("Error 23: color R,G,B limits are [0-255] :o", 1);
	else if (error_nb == 42)
		ft_putendl_fd("Error 42: malloc fail D:", 1);
	else
		ft_putendl_fd("Error 0: not specified... yet ;)", 1);
	exit(-1);
}

static void	rt_exit_ko_ten(int error_nb)
{
	if (error_nb == 10)
		ft_putendl_fd("Error 10: unknown element in .rt file :/", 1);
	else if (error_nb == 11)
		ft_putendl_fd("Error 11: R and A elements must be unique :o", 1);
	else if (error_nb == 12)
		ft_putendl_fd("Error 12: resolution x and y must be > 0 :o", 1);
	else if (error_nb == 13)
		ft_putendl_fd("Error 13: unknown character between infos :/", 1);
	else if (error_nb == 14)
		ft_putendl_fd("Error 14: you must use , to separate values :o", 1);
	else if (error_nb == 15)
		ft_putendl_fd("Error 15: unknown character before value :/", 1);
	else if (error_nb == 16)
		ft_putendl_fd("Error 16: there is a . non-followed by a number :o", 1);
	else if (error_nb == 17)
		ft_putendl_fd("Error 17: there is a limit of 10 digits, sorry :o", 1);
	else if (error_nb == 18)
		ft_putendl_fd("Error 18: no camera available, what a shame :p", 1);
	else if (error_nb > 18)
		rt_exit_ko_twenty(error_nb);
	exit(-1);
}

void		rt_exit_ko(int error_nb)
{
	if (error_nb == 1)
		ft_putendl_fd("Error 1: missing argument :'( I need a file name", 1);
	else if (error_nb == 2)
		ft_putendl_fd("Error 2: wrong file type :'( I need a .rt file", 1);
	else if (error_nb == 3)
		ft_putendl_fd("Error 3: wrong file name :'( I can't find it", 1);
	else if (error_nb > 3)
		rt_exit_ko_ten(error_nb);
	exit(-1);
}

void		rt_exit_ko_scn(int error_nb, t_scn *scn)
{
	rt_clear_scene(&scn, scn->cams, scn->lights, scn->objs);
	rt_exit_ko(error_nb);
}

void		rt_exit_ko_line(int error_nb, t_scn *scn, char *line)
{
	free(line);
	if (error_nb >= 10 && error_nb < 40)
	{
		ft_putstr_fd("( Stop on line ", 1);
		ft_putnbr_fd(scn->line_nb, 1);
		ft_putendl_fd(" )", 1);
	}
	rt_clear_scene(&scn, scn->cams, scn->lights, scn->objs);
	rt_exit_ko(error_nb);
}
