/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:07:01 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:07:02 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		clear_rt(t_rt **rt, t_scn *scn)
{
	if (rt && *rt)
	{
		rt_clear_scene_elements(scn->amb, scn->cams, scn->lights, scn->objs);
		rt_clear_scene(&scn, scn->ray_light, scn->ray_shad, scn->hit);
		free(*rt);
	}
}

static t_rt	*init_rt(void)
{
	t_rt	*rt;

	if (!(rt = ft_memalloc(sizeof(t_rt))))
		rt_exit(ERR_MALLOC);
	rt->file = rt_init_file();
	rt->scn = rt_init_scene();
	rt->img = rt_init_image();
	rt->mlx_ptr = NULL;
	rt->win_ptr = NULL;
	rt->i = 0;
	rt->j = 0;
	rt->loop = 0;
	return (rt);
}

static void	minirt(char *file_name, int fd)
{
	t_rt	*rt;

	rt = init_rt();
	rt->file->name = file_name;
	rt->file->fd = fd;
	rt_parse(rt, rt->file);
	close(fd);
	ft_putstr_fd("Parsing ended successfully ^^ Loading image... ", 1);
	rt_image(rt, &rt->scn->cams, 1);
}

int			main(int ac, char **av)
{
	int		fd;

	ft_putendl_fd("MiniRT is starting! Hi :)", 1);
	if (ac < 2 || ac > 3)
		rt_exit(ERR_AC);
	if (!(ft_strend(av[1], ".rt")))
		rt_exit(ERR_FILE_RT);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		rt_exit(ERR_FILE_UNKN);
	minirt(av[1], fd);
	return (0);
}
