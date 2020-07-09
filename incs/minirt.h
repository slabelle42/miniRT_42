#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

typedef struct	s_simul_parse
{
	char		*file_name;
	int			win_H;
	int			win_W;
	double		fov;
	double		ray_o_x;
	double		ray_o_y;
	double		ray_o_z;
	double		ray_d_x;
	double		ray_d_y;
	double		ray_d_z;
	double		li_o_x;
	double		li_o_y;
	double		li_o_z;
	double		li_i;
	double		obj_o_x;
	double		obj_o_y;
	double		obj_o_z;
	double		obj_r;
	int			obj_red;
	int			obj_green;
	int			obj_blue;
}				t_simul_parse;

typedef struct	s_rt
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*win_name;
	int			win_H;
	int			win_W;
	double		fov;
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

typedef struct	s_light
{
	t_vector	*origin;
	double		intensity;
}				t_light;

typedef struct	s_object
{
	char		type;
	t_vector	*origin;
	double		size;
	int			color;
}				t_object;

void			rt_parse(t_simul_parse *sp);

t_rt			*rt_init_rt(t_simul_parse *sp);
t_vector		*rt_init_vector(double x, double y, double z);
t_ray			*rt_init_ray(t_vector *origin, t_vector *direction);
t_light			*rt_init_light(t_vector *origin, double intensity);
t_object		*rt_init_sphere(t_vector *origin, double radius, int color);

void			rt_display(t_rt *rt, t_ray *ray, t_light *light, t_object *sphere);
void			rt_display_sphere(t_rt *rt, t_ray *ray, t_light *light, t_object *sphere);

double			rt_math_dotproduct(t_vector *vec1, t_vector *vec2);
char			rt_math_intersect(t_ray *ray, t_object *sphere,
					t_vector *intersect_pos, t_vector *intersect_norm);
double			rt_math_norm2(t_vector *vec);
void			rt_math_normalize(t_vector *vec);

int				rt_color_rgbtoi(int red, int green, int blue);

#endif
