/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:07:01 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:07:02 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	minirt(char **av)
{
	int		fd;
	t_scn	*scn;
	int		ret;
	char	*line;

	if (!(ft_strend(av[1], ".rt")))
		rt_exit_ko(ERR_FILE_NAME_RT);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		rt_exit_ko(ERR_FILE_NAME_UNKN);
	if (!(scn = rt_init_scene(av[1])))
		rt_exit_ko_scn(ERR_MALLOC, scn);
	while ((ret = get_next_line(fd, &line)))
	{
		(scn->line_nb)++;
		rt_parse_line(scn, line);
		free(line);
	}
	close(fd);
	rt_parse_checks(scn);
	ft_putendl_fd(
		"Parsing ended successfully, let's see what we've got here ^^", 1);
	rt_display_window(scn);
}

int			main(int ac, char **av)
{
	ft_putendl_fd("MiniRT is starting! Hi :)", 1);
	if (ac == 2)
		minirt(av);
	else
		rt_exit_ko(ERR_FILE_NAME_MISS);
	return (0);
}
