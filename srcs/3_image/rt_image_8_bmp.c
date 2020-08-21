/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_image_8_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:10:04 by slabelle          #+#    #+#             */
/*   Updated: 2020/08/21 16:10:17 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			rt_image_bmpbody(t_rt *rt, char **bmp)
{
	unsigned int	i;
	int				y;
	int				x;

	i = HEADER_SIZE;
	y = -1;
	while (++y < rt->scn->win_y)
	{
		x = -1;
		while (++x < rt->scn->win_x)
		{
			*(*bmp + i++) = *(rt->img->addr +
				(((rt->scn->win_y - y - 1) * rt->scn->win_x) + x) * 4 + 0);
			*(*bmp + i++) = *(rt->img->addr +
				(((rt->scn->win_y - y - 1) * rt->scn->win_x) + x) * 4 + 1);
			*(*bmp + i++) = *(rt->img->addr +
				(((rt->scn->win_y - y - 1) * rt->scn->win_x) + x) * 4 + 2);
		}
	}
}

static void			rt_image_bmpheader(t_rt *rt, char **bmp,
						unsigned int img_size, unsigned int bmp_size)
{
	*(unsigned char *)*bmp = 'B';
	*(unsigned char *)(*bmp + 1) = 'M';
	*(unsigned int *)(*bmp + 2) = (bmp_size);
	*(unsigned int *)(*bmp + 6) = (unsigned int)0;
	*(unsigned char *)(*bmp + 10) = HEADER_SIZE;
	*(unsigned int *)(*bmp + 14) = HEADER_SIZE - 14;
	*(unsigned int *)(*bmp + 18) = rt->scn->win_x;
	*(unsigned int *)(*bmp + 22) = rt->scn->win_y;
	*(unsigned short *)(*bmp + 26) = 1;
	*(unsigned short *)(*bmp + 28) = 24;
	*(unsigned int *)(*bmp + 30) = 0;
	*(unsigned int *)(*bmp + 34) = (unsigned int)img_size;
	*(unsigned int *)(*bmp + 38) = 3780;
	*(unsigned int *)(*bmp + 42) = 3780;
	*(unsigned int *)(*bmp + 46) = 0;
	*(unsigned int *)(*bmp + 50) = 0;
}

static char			*rt_image_bmpname(t_rt *rt)
{
	unsigned int	name_len;
	char			*file_name;

	name_len = ft_strlen(rt->file->name);
	if (!(file_name = ft_memalloc(name_len + 4 + 1)))
		rt_exit(ERR_MALLOC);
	ft_strlcpy(file_name, rt->file->name, name_len + 1);
	ft_strlcat(file_name, ".bmp", name_len + 4 + 1);
	return (file_name);
}

void				rt_image_bmp(t_rt *rt)
{
	char			*file_name;
	unsigned int	img_size;
	unsigned int	bmp_size;
	char			*bmp;
	int				fd;

	file_name = rt_image_bmpname(rt);
	img_size = rt->scn->win_x * rt->scn->win_y * 3;
	bmp_size = img_size + HEADER_SIZE;
	if (!(bmp = ft_memalloc(bmp_size)))
	{
		clear_rt(&rt, rt->scn);
		rt_exit(ERR_MALLOC);
	}
	ft_bzero(bmp, bmp_size);
	rt_image_bmpheader(rt, &bmp, img_size, bmp_size);
	rt_image_bmpbody(rt, &bmp);
	if ((fd = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644)) < 0)
		rt_exit(ERR_FILE_UNKN);
	write(fd, bmp, bmp_size);
	close(fd);
	free(file_name);
	free(bmp);
}
