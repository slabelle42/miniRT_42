/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_4_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 21:14:32 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/01 21:14:35 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_parse_checks(t_scn *scn)
{
	if (scn->win_h == -1 || scn->win_w == -1)
		rt_exit_ko_scn(ERR_FILE_RES, scn);
	if (!scn->cams)
		rt_exit_ko_scn(ERR_FILE_CAM, scn);
	if (!scn->lights)
		rt_exit_ko_scn(ERR_FILE_LIGHT, scn);
	if (!scn->objs)
		rt_exit_ko_scn(ERR_FILE_OBJ, scn);
}
