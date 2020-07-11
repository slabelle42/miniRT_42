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
	double		cam_o_x;
	double		cam_o_y;
	double		cam_o_z;
	double		cam_d_x;
	double		cam_d_y;
	double		cam_d_z;
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
}				t_rt;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_camera
{
	t_vector	*origin;
	t_vector	*direction;
	double		fov;
}				t_camera;

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_light
{
	t_vector	*origin;
	double		intensity;
	t_color		*color;
}				t_light;

typedef struct	s_object
{
	char		type;
	t_vector	*origin;
	double		size;
	t_color		*color;
}				t_object;

typedef struct	s_delta
{
	double		a;
	double		b;
	double		c;
	double		delta;
}				t_delta;

typedef struct	s_display
{
	int			i;
	int			j;
	double		solution;
	t_vector	*intersect_pos;
	t_vector	*intersect_norm;
	t_vector	*diff;
	double		pix_intensity;
}				t_display;

void			rt_parse(t_simul_parse *sp);

t_rt			*rt_init_rt(t_simul_parse *sp);
t_vector		*rt_init_vector(double x, double y, double z);
t_camera		*rt_init_camera(t_vector *origin, t_vector *direction,
					double fov);
t_color			*rt_init_color(int red, int green, int blue);
t_light			*rt_init_light(t_vector *origin, double intensity);
t_object		*rt_init_sphere(t_vector *origin, double radius,
					t_color *color);
t_delta			*rt_init_delta(double a, double b, double c);
t_display		*rt_init_display(t_vector *intersect_pos,
					t_vector *intersect_norm, t_vector *diff);

void			rt_display_scene(t_rt *rt, t_camera *camera, t_light *light,
					t_object *sphere, t_display *display);
void			rt_display_window(t_rt *rt, t_camera *camera, t_light *light,
					t_object *sphere, t_display *display);
void			rt_display(t_rt *rt, t_camera *camera, t_light *light,
					t_object *sphere);

void			rt_display_adjustcam(t_rt *rt, t_camera *camera,
					t_display *display);
void			rt_display_getdiff(t_light *light, t_display *display);
void			rt_display_pixintens(t_light *light, t_display *display);

double			rt_math_solution(t_delta *delta);
double			rt_math_norm2(t_vector *vec);
void			rt_math_normalize(t_vector *vec);
double			rt_math_dotproduct(t_vector *vec1, t_vector *vec2);
double			rt_math_intersect(t_camera *camera, t_object *sphere);
void			rt_math_pos_norm(t_camera *camera, t_object *sphere,
					t_display *display);

int				rt_color_rgbtoi(int red, int green, int blue);

#endif
