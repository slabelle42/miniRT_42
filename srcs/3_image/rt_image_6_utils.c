/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_6_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:05:51 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:05:52 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		rt_image_adjustray(t_rt *rt, t_scn *scn, t_cam *cam, t_ray *ray)
{
	ray->ori->x_r = cam->ori->x_r;
	ray->ori->y_g = cam->ori->y_g;
	ray->ori->z_b = cam->ori->z_b;
	ray->dir->y_g = rt->i - scn->win_y / 2;
	ray->dir->x_r = rt->j - scn->win_x / 2;
	ray->dir->z_b = -scn->win_x / (2 * tan(cam->fov / 2));
	rt_math_normalize(ray->dir);
}

double		rt_image_rgbtoi(t_info3 *color)
{
	int		r;
	int		g;
	int		b;

	r = pow(color->x_r * 255 * 500, 1 / 2.2);
	g = pow(color->y_g * 255 * 500, 1 / 2.2);
	b = pow(color->z_b * 255 * 500, 1 / 2.2);
	return (r * 65536 + g * 256 + b);
}

double		rt_image_getdistance(t_info3 *ray_ori, t_info3 *diff,
				t_info3 *thing_ori)
{
	double	norm2;

	rt_info3_diff(thing_ori, ray_ori, diff);
	norm2 = rt_info3_dot(diff, diff);
	return (norm2);
}

t_info3		*rt_image_getintensity(t_info3 *color, double intens)
{
	t_info3	*color_intens;

	color_intens = rt_init_info3();
	color_intens->x_r = color->x_r / 255.0 * intens;
	color_intens->y_g = color->y_g / 255.0 * intens;
	color_intens->z_b = color->z_b / 255.0 * intens;
	return (color_intens);
}

void		rt_image_getmessage(t_rt *rt, t_scn *scn)
{
	rt->loop = 1;
	ft_putstr_fd("--> Camera ", 1);
	ft_putnbr_fd(scn->cam_current, 1);
	ft_putendl_fd(" is displayed", 1);
}
