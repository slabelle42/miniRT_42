/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct_3_ambiance.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:04:54 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:04:55 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_amb		*rt_init_ambiance(void)
{
	t_amb	*amb;

	if (!(amb = ft_memalloc(sizeof(t_amb))))
		rt_exit(ERR_MALLOC);
	amb->intens = -1.0;
	amb->color = rt_init_info3();
	return (amb);
}

void		rt_clear_ambiance(t_amb *amb)
{
	if (amb)
	{
		if (amb->color)
			free(amb->color);
		free(amb);
	}
}
