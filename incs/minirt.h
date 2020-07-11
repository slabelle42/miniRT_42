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
	double				cam_ori_x;
	double				cam_ori_y;
	double				cam_ori_z;
	double				cam_dir_x;
	double				cam_dir_y;
	double				cam_dir_z;
	double				li_ori_x;
	double				li_ori_y;
	double				li_ori_z;
	double				li_intensity;
	char				obj1_type;
	double				obj1_ori_x;
	double				obj1_ori_y;
	double				obj1_ori_z;
	double				obj1_rad;
	int					obj1_R;
	int					obj1_G;
	int					obj1_B;
	char				obj2_type;
	double				obj2_ori_x;
	double				obj2_ori_y;
	double				obj2_ori_z;
	double				obj2_rad;
	int					obj2_R;
	int					obj2_G;
	int					obj2_B;
}						t_simul_parse;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_color
{
	int					R;
	int					G;
	int					B;
}						t_color;

typedef struct			s_display
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*win_name;
	int					win_H;
	int					win_W;
	int					i;
	int					j;
	double				pix_intensity;
	t_vector			*origin;
	t_color				*color;
}						t_display;

typedef struct			s_cameras
{
	t_vector			*origin;
	t_vector			*direction;
	double				fov;
	struct s_cameras	*next;
}						t_cameras;

typedef struct			s_lights
{
	t_vector			*origin;
	double				intensity;
	t_color				*color;
	struct s_lights		*next;
}						t_lights;

typedef struct			s_objects
{
	char				type;
	t_vector			*origin;
	double				size;
	t_color				*color;
	struct s_objects	*next;
}						t_objects;

typedef struct			s_intersection
{
	double				solution;
	t_vector			*position;
	t_vector			*normal;
	t_vector			*diff;
}						t_intersection;

typedef struct			s_delta
{
	double				a;
	double				b;
	double				c;
	double				delta;
}						t_delta;

void					rt_parse(t_simul_parse *sp);

t_vector				*rt_init_vector(double x, double y, double z);
t_color					*rt_init_color(int R, int G, int B);
t_display				*rt_init_display(t_simul_parse *sp, t_vector *origin,
							t_color *color);
t_cameras				*rt_init_camera(t_vector *origin, t_vector *direction,
							double fov);
t_lights				*rt_init_light(t_vector *origin, double intensity);
t_objects				*rt_init_object(char type, t_vector *origin,
							double size, t_color *color);
int						rt_add_object(t_objects **objects,
							t_objects *new_object);
int						rt_clear_objects(t_objects **objects);
t_intersection			*rt_init_intersection(t_vector *position,
							t_vector *normal, t_vector *diff);
t_delta					*rt_init_delta(double a, double b, double c);

void					rt_display_object(t_display *display,
							t_cameras *cameras, t_lights *lights,
							t_intersection *intersection);
void					rt_display_scene(t_display *display, t_cameras *cameras,
							t_lights *lights, t_objects *objects,
							t_intersection *intersection);
void					rt_display_window(t_display *display,
							t_cameras *cameras, t_lights *lights,
							t_objects *objects, t_intersection *intersection);
void					rt_display(t_display *display, t_cameras *cameras,
							t_lights *lights, t_objects *objects);

void					rt_display_adjustcam(t_display *display,
							t_cameras *camera);
void					rt_display_getobjparams(t_display *display,
							t_objects *object);
void					rt_display_getdiff(t_lights *light,
							t_intersection *intersection);
void					rt_display_pixintens(t_display *display,
							t_lights *light, t_intersection *intersection);

double					rt_math_solution(t_delta *delta);
double					rt_math_norm2(t_vector *vec);
void					rt_math_normalize(t_vector *vec);
double					rt_math_dotproduct(t_vector *vec1, t_vector *vec2);
double					rt_math_intersect(t_cameras *camera, t_objects *object);
void					rt_math_pos_norm(t_display *display, t_cameras *camera,
							t_intersection *intersection);

int						rt_color_rgbtoi(int R, int G, int B);

#endif
