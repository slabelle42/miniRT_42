#include "minirt.h"

int			main(int ac, char **av)
{
	int		fd;
	t_scn	*scn;
	int		ret;
	char	*line;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (-1);
		if (!(scn = rt_init_scene()))
			return (-1);
		scn->file_name = av[1];
		while ((ret = get_next_line(fd, &line)))
		{
			if ((rt_parse_line(scn, line)) == -1)
				return (-1);
			free(line);
		}
		close(fd);
		rt_display_window(scn);
		rt_clear_scene_structs(scn->ori, scn->color);
		rt_clear_scene(&scn, scn->cams, scn->lights, scn->objs);
	}
	return (0);
}
