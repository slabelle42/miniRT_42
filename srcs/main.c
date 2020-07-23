#include "minirt.h"

int			main(int ac, char **av)
{
	int		fd;
	t_scn	*scn;
	int		ret;
	char	*line;

	if (ac == 2)
	{
		ft_putendl_fd("MiniRT is starting! Hi :)", 1);
		if ((fd = open(av[1], O_RDONLY)) == -1)
			rt_exit_ko(2);
		if (!(scn = rt_init_scene()))
			rt_exit_ko(42);
		scn->file_name = av[1];
		while ((ret = get_next_line(fd, &line)))
		{
			if ((rt_parse_line(scn, line)) == -1)
				rt_exit_ko(42);
			free(line);
		}
		close(fd);
		rt_display_window(scn);
	}
	else
		rt_exit_ko(1);
	return (0);
}
