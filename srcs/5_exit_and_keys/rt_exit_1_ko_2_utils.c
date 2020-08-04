/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit_1_ko_2_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:18:03 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/04 11:18:05 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_exit_ko_scn(int error_nb, t_scn *scn)
{
	rt_clear_scene(&scn, scn->cams, scn->lights, scn->objs);
	rt_exit_ko(error_nb);
}

void	rt_exit_ko_line(int error_nb, t_scn *scn, char *line)
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

void	rt_exit_ko_message(int error_nb, char *message)
{
	ft_putstr_fd("Error ", 1);
	ft_putnbr_fd(error_nb, 1);
	ft_putstr_fd(": ", 1);
	ft_putendl_fd(message, 1);
}
