/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_3_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:03:51 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:04:08 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_parse_move(t_scn *scn, char *line)
{
	while (line[scn->i] == ' ' || line[scn->i] == '\t')
		(scn->i)++;
	if (line[scn->i] == '\0')
		rt_exit_ko_line(19, scn, line);
}
