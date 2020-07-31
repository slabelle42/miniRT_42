/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structs_6_math.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:05:15 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:05:16 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect		*rt_init_intersection(void)
{
	t_intersect	*intersect;

	if (!(intersect = ft_memalloc(sizeof(t_intersect))))
		return (NULL);
	intersect->solution = 0;
	if (!(intersect->pos = rt_init_vector()))
		return (NULL);
	if (!(intersect->norm = rt_init_vector()))
		return (NULL);
	if (!(intersect->diff = rt_init_vector()))
		return (NULL);
	return (intersect);
}

void			rt_clear_intersection(t_intersect **intersect,
					t_vec *pos, t_vec *norm, t_vec *diff)
{
	if (intersect)
	{
		free(pos);
		free(norm);
		free(diff);
		free(*intersect);
		*intersect = NULL;
	}
}

t_delta			*rt_init_delta(double a, double b, double c)
{
	t_delta		*delta;

	if (!(delta = ft_memalloc(sizeof(t_delta))))
		return (NULL);
	delta->a = a;
	delta->b = b;
	delta->c = c;
	delta->delta = b * b - 4 * a * c;
	return (delta);
}
