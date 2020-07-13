#ifndef MINIRT_H
# define MINIRT_H


# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"


typedef struct		s_simul_parse
{
	char			*file_name;
	int				win_H;
	int				win_W;
	double			fov;
	double			cam_ori_x;
	double			cam_ori_y;
	double			cam_ori_z;
	double			cam_dir_x;
	double			cam_dir_y;
	double			cam_dir_z;
	double			li_ori_x;
	double			li_ori_y;
	double			li_ori_z;
	double			li_intens;
	char			obj1_type;
	double			obj1_ori_x;
	double			obj1_ori_y;
	double			obj1_ori_z;
	double			obj1_rad;
	int				obj1_R;
	int				obj1_G;
	int				obj1_B;
	char			obj2_type;
	double			obj2_ori_x;
	double			obj2_ori_y;
	double			obj2_ori_z;
	double			obj2_rad;
	int				obj2_R;
	int				obj2_G;
	int				obj2_B;
}					t_simul_parse;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_color
{
	int				R;
	int				G;
	int				B;
}					t_color;

typedef struct		s_cams
{
	t_vec			*ori;
	t_vec			*dir;
	double			fov;
	struct s_cams	*next;
}					t_cams;

typedef struct		s_lights
{
	t_vec			*ori;
	double			intens;
	t_color			*color;
	struct s_lights	*next;
}					t_lights;

typedef struct		s_objs
{
	char			type;
	t_vec			*ori;
	double			size;
	t_color			*color;
	struct s_objs	*next;
}					t_objs;

typedef struct		s_scn
{
	char			*file_name;
	int				win_H;
	int				win_W;
	struct s_cams	*cams;
	struct s_lights	*lights;
	struct s_objs	*objs;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				i;
	int				j;
	double			pix_intens;
	t_vec			*ori;
	t_color			*color;
}					t_scn;

typedef struct		s_intersect
{
	double			solution;
	t_vec			*pos;
	t_vec			*norm;
	t_vec			*diff;
}					t_intersect;

typedef struct		s_delta
{
	double			a;
	double			b;
	double			c;
	double			delta;
}					t_delta;


t_scn				*rt_parse(t_simul_parse *sp);


t_vec				*rt_init_vector();
t_color				*rt_init_color();

t_cams				*rt_init_camera();
t_cams				*rt_fill_camera(t_cams *cam, double fov);
t_cams				*rt_fill_camera_origin(t_cams *cam,
						double x, double y, double z);
t_cams				*rt_fill_camera_direction(t_cams *cam,
						double x, double y, double z);
int					rt_clear_cameras(t_cams **cams);

t_lights			*rt_init_light();
t_lights			*rt_fill_light(t_lights *light, double intens);
t_lights			*rt_fill_light_origin(t_lights *light,
						double x, double y, double z);
t_lights			*rt_fill_light_color(t_lights *light, int R, int G, int B);
int					rt_clear_lights(t_lights **lights);

t_objs				*rt_init_object();
t_objs				*rt_fill_object(t_objs *obj, char type, double size);
t_objs				*rt_fill_object_origin(t_objs *obj,
						double x, double y, double z);
t_objs				*rt_fill_object_color(t_objs *obj, int R, int G, int B);
int					rt_add_object(t_objs **objs, t_objs *new_obj);
int					rt_clear_objects(t_objs **objs);

t_scn				*rt_init_scene();
t_scn				*rt_fill_scene_R(t_scn *scn, char *file_name,
					int win_H, int win_W);
t_scn				*rt_fill_scene_CLO(t_scn *scn,
						t_cams *cams, t_lights *lights, t_objs *objs);
int					rt_clear_scene(t_scn **scn,
						t_cams *cams, t_lights *lights, t_objs *objs);
void				rt_clear_scene_structs(t_vec *ori, t_color *color);

t_intersect			*rt_init_intersection();
int					rt_clear_intersection(t_intersect **intersect,
						t_vec *pos, t_vec *norm, t_vec *diff);
t_delta				*rt_init_delta(double a, double b, double c);


void				rt_display_pixel(t_scn *scn, t_intersect *intersect);
void				rt_display_object(t_scn *scn, t_intersect *intersect);
void				rt_display_scene(t_scn *scn);
void				rt_display_window(t_scn *scn);

void				rt_display_adjustcam(t_scn *scn);
void				rt_display_getobjparams(t_scn *scn, t_objs *obj);
void				rt_display_getdiff(t_lights *light, t_intersect *intersect);
void				rt_display_pixintens(t_scn *scn, t_intersect *intersect);


double				rt_math_solution(t_delta *delta);
double				rt_math_norm2(t_vec *vec);
void				rt_math_normalize(t_vec *vec);
double				rt_math_dotproduct(t_vec *vec1, t_vec *vec2);
double				rt_math_intersect(t_cams *cam, t_objs *obj);
void				rt_math_pos_norm(t_scn *scn, t_intersect *intersect);


int					rt_color_rgbtoi(int R, int G, int B);


#endif
