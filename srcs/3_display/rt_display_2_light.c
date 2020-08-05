/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_display_3_shadow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:51:41 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/02 17:51:47 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_display_light(t_scn *scn, t_intersect *intersect)
{
	rt_display_getdiff(scn->lights, intersect);
	rt_display_pixintens(scn, intersect);
}
