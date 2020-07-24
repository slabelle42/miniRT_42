#include "minirt.h"

static void	minirt(char **av)
{
	int		fd;
	t_scn	*scn;
	int		ret;
	char	*line;

	if (!(ft_strend(av[1], ".rt")))
		rt_exit_ko_noscn(2);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		rt_exit_ko_noscn(3);
	if (!(scn = rt_init_scene()))
		rt_exit_ko(42, scn);
	scn->file_name = av[1];
	while ((ret = get_next_line(fd, &line)))
	{
		if ((rt_parse_line(scn, line)) == -1)
			rt_exit_ko(42, scn);
		free(line);
	}
	close(fd);
	rt_display_window(scn);
}

int			main(int ac, char **av)
{
	ft_putendl_fd("MiniRT is starting! Hi :)", 1);
	if (ac == 2)
		minirt(av);
	else
		rt_exit_ko_noscn(1);
	return (0);
}
