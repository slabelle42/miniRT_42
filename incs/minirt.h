#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

typedef struct			s_simul_parse
{
	char				*file_name;
	int					win_H;
	int					win_W;
	double				fov;
	double				cam_o_x;
	double				cam_o_y;
	double				cam_o_z;
	double				cam_d_x;
	double				cam_d_y;
	double				cam_d_z;
	double				li_o_x;
	double				li_o_y;
	double				li_o_z;
	double				li_i;
	char				s1_type;
	double				s1_o_x;
	double				s1_o_y;
	double				s1_o_z;
	double				s1_r;
	int					s1_red;
	int					s1_green;
	int					s1_blue;
	char				s2_type;
	double				s2_o_x;
	double				s2_o_y;
	double				s2_o_z;
	double				s2_r;
	int					s2_red;
	int					s2_green;
	int					s2_blue;
}						t_simul_parse;

typedef struct			s_rt
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*win_name;
	int					win_H;
	int					win_W;
}						t_rt;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_camera
{
	t_vector			*origin;
	t_vector			*direction;
	double				fov;
}						t_camera;

typedef struct			s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

typedef struct			s_light
{
	t_vector			*origin;
	double				intensity;
	t_color				*color;
}						t_light;

typedef struct			s_objects
{
	char				type;
	t_vector			*origin;
	double				size;
	t_color				*color;
	struct s_objects	*next;
}						t_objects;

typedef struct			s_delta
{
	double				a;
	double				b;
	double				c;
	double				delta;
}						t_delta;

typedef struct			s_display
{
	int					i;
	int					j;
	double				solution;
	t_vector			*intersect_pos;
	t_vector			*intersect_norm;
	t_vector			*diff;
	double				pix_intensity;
	double				sphere_x;
	double				sphere_y;
	double				sphere_z;
	int					sphere_red;
	int					sphere_green;
	int					sphere_blue;
}						t_display;

void					rt_parse(t_simul_parse *sp);

t_rt					*rt_init_rt(t_simul_parse *sp);
t_vector				*rt_init_vector(double x, double y, double z);
t_camera				*rt_init_camera(t_vector *origin, t_vector *direction,
							double fov);
t_color					*rt_init_color(int red, int green, int blue);
t_light					*rt_init_light(t_vector *origin, double intensity);
t_objects				*rt_init_object(char type, t_vector *origin,
							double size, t_color *color);
int						rt_add_object(t_objects **objects,
							t_objects *new_object);
int						rt_clear_objects(t_objects **objects);
t_delta					*rt_init_delta(double a, double b, double c);
t_display				*rt_init_display(t_vector *intersect_pos,
							t_vector *intersect_norm, t_vector *diff);

void					rt_display_object(t_rt *rt, t_camera *camera,
							t_light *light, t_display *display);
void					rt_display_scene(t_rt *rt, t_camera *camera,
							t_light *light, t_objects *objects,
							t_display *display);
void					rt_display_window(t_rt *rt, t_camera *camera,
							t_light *light, t_objects *objects,
							t_display *display);
void					rt_display(t_rt *rt, t_camera *camera, t_light *light,
							t_objects *objects);

void					rt_display_adjustcam(t_rt *rt, t_camera *camera,
							t_display *display);
void					rt_display_getdiff(t_light *light, t_display *display);
void					rt_display_pixintens(t_light *light,
							t_display *display);

double					rt_math_solution(t_delta *delta);
double					rt_math_norm2(t_vector *vec);
void					rt_math_normalize(t_vector *vec);
double					rt_math_dotproduct(t_vector *vec1, t_vector *vec2);
double					rt_math_intersect(t_camera *camera, t_objects *sphere);
void					rt_math_pos_norm(t_camera *camera, t_display *display);

int						rt_color_rgbtoi(int red, int green, int blue);

#endif
