/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_4_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:06:18 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:06:20 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		rt_math_normalize(t_info3 *info3)
{
	double	norm;

	norm = sqrt(rt_info3_dot(info3, info3));
	info3->x_r /= norm;
	info3->y_g /= norm;
	info3->z_b /= norm;
}

double		rt_math_cosine(t_info3 *info3a, t_info3 *info3b)
{
	double	dot;
	double	magnitude1;
	double	magnitude2;

	dot = rt_info3_dot(info3a, info3b);
	magnitude1 = sqrt(rt_info3_dot(info3a, info3a));
	magnitude2 = sqrt(rt_info3_dot(info3b, info3b));
	return (dot / (magnitude1 * magnitude2));
}

double		rt_math_lambertian(t_hit *hit, t_light *light)
{
	t_info3	*diff;
	double	dot;
	double	intens;

	diff = rt_info3_diff(light->ori, hit->ori);
	rt_math_normalize(diff);
	dot = rt_info3_dot(diff, hit->norm);
	free(diff);
	intens = (dot > 0) ? dot : 0.0;
	intens *= light->intens;
	return (intens);
}
