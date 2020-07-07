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
	void		*img_ptr;
	char		*win_name;
	int			win_W;
	int			win_H;
}				t_rt;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	*origin;
	t_vector	*direction;
}				t_ray;

typedef struct	s_object
{
	char		type;
	t_vector	*origin;
	double		radius;
	int			color;
}				t_object;

int				rt_color_rgbtoi(int red, int green, int blue);

int				rt_display_sphere(t_rt *rt, t_object *sphere);
int				rt_display_xpm(char *xpm_file_name, t_rt *rt, int x, int y);

t_vector		*rt_init_vector(double x, double y, double z);
t_ray			*rt_init_ray(t_vector *origin, t_vector *direction);
t_object		*rt_init_sphere(t_vector *origin, double radius, int color);

double			rt_vector_dot(t_vector *vec1, t_vector *vec2);
char			rt_vector_intersec(t_ray *ray, t_object *sphere);
double			rt_vector_norm2(t_vector *vec);
void			rt_vector_normalize(t_vector *vec);

#endif
