#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

typedef struct	s_rt
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*win_name;
	void		*img_ptr;
	int			res_W;
	int			res_H;
	int			color_red;
	int			color_green;
	int			color_blue;
}				t_rt;

int				rt_color_rgbtoi(int red, int green, int blue);

int				rt_display_pixels(t_rt *rt);
int				rt_display_xpm(char *xpm_file_name, t_rt *rt, int x, int y);

#endif
