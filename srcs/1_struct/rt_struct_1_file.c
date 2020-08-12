/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct_1_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:04:22 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:04:41 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_file		*rt_init_file(void)
{
	t_file	*file;

	if (!(file = ft_memalloc(sizeof(t_file))))
		rt_exit(ERR_MALLOC);
	file->name = NULL;
	file->fd = 0;
	file->ret = 0;
	file->line = NULL;
	file->line_nb = 0;
	return (file);
}
