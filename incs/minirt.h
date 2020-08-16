/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:41:39 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:41:44 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define KEYLINUX_ESC	65307
# define KEYLINUX_C		99
# define KEYMAC_ESC		53
# define KEYMAC_C		8

# define ERR_AC			-1
# define ERR_FILE_RT	-2
# define ERR_FILE_UNKN	-3
# define ERR_ELEM_UNIQ	-4
# define ERR_ELEM_UNKN	-5
# define ERR_ELEM_MISS	-6
# define ERR_ELEM_WRG	-7
# define ERR_INFO_NULL	-8
# define ERR_INFO_DIGIT	-9
# define ERR_LIMIT		-10
# define ERR_SHAD		-11
# define ERR_MALLOC		-99

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct		s_file
{
	char			*name;
	int				fd;
	int				ret;
	char			*line;
	int				line_nb;
}					t_file;

typedef struct		s_info3
{
	double			x_r;
	double			y_g;
	double			z_b;
}					t_info3;

typedef struct		s_amb
{
	double			intens;
	t_info3			*color;
}					t_amb;

typedef struct		s_cam
{
	t_info3			*ori;
	t_info3			*vec;
	double			fov;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light
{
	t_info3			*ori;
	double			intens;
	t_info3			*color;
	struct s_light	*next;
}					t_light;

typedef struct		s_obj
{
	char			type;
	t_info3			*ori;
	t_info3			*vec;
	t_info3			*tri;
	double			size1;
	double			size2;
	t_info3			*color;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_scn
{
	int				win_x;
	int				win_y;
	t_amb			*amb;
	t_cam			*cams;
	int				cam_nb;
	int				cam_current;
	t_light			*lights;
	t_obj			*objs;
	int				is_shad;
}					t_scn;

typedef struct		s_ray
{
	t_info3			*ori;
	t_info3			*dir;
}					t_ray;

typedef struct		s_hit
{
	t_ray			*ray_light;
	t_ray			*ray_shad;
	t_info3			*ori;
	t_info3			*norm;
	t_info3			*color;
}					t_hit;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct		s_rt
{
	t_file			*file;
	t_scn			*scn;
	t_hit			*hit;
	t_img			*img;
	void			*mlx_ptr;
	void			*win_ptr;
	int				i;
	int				j;
	int				loop;
}					t_rt;

void				clear_rt(t_rt **rt, t_scn *scn, t_hit *hit);

t_file				*rt_init_file(void);
t_info3				*rt_init_info3(void);
void				rt_copy_info3(t_info3 *info3, t_info3 *cpy);
void				rt_fill_info3(t_info3 *info3, double a, double b, double c);
t_amb				*rt_init_ambiance(void);
void				rt_clear_ambiance(t_amb *amb);
t_cam				*rt_init_camera(void);
int					rt_add_camera(t_cam **cams, t_cam *new_cam);
void				rt_clear_cameras(t_cam **cams);
t_light				*rt_init_light(void);
int					rt_add_light(t_light **lights, t_light *new_light);
void				rt_clear_lights(t_light **lights);
t_obj				*rt_init_object(void);
int					rt_add_object(t_obj **objs, t_obj *new_obj);
void				rt_clear_objects(t_obj **objs);
t_scn				*rt_init_scene(void);
void				rt_clear_scene_elements(t_amb *amb, t_cam *cams,
						t_light *lights, t_obj *objs);
void				rt_clear_scene(t_scn **scn);
t_ray				*rt_init_ray(void);
void				rt_clear_ray(t_ray *ray);
t_hit				*rt_init_hit(void);
void				rt_clear_hit(t_hit *hit);
t_img				*rt_init_image(void);

void				rt_parse(t_rt *rt, t_file *file);
void				rt_parse_resolution(t_rt *rt, t_scn *scn, char *line);
void				rt_parse_ambiance(t_rt *rt, t_amb *amb, char *line);
void				rt_parse_camera(t_rt *rt, t_cam **cams, char *line);
void				rt_parse_light(t_rt *rt, t_light **lights, char *line);
void				rt_parse_shadow(t_rt *rt, t_scn *scn, char *line);
void				rt_parse_sphere(t_rt *rt, t_obj **objs, char *line);
void				rt_parse_plane(t_rt *rt, t_obj **objs, char *line);
void				rt_parse_square(t_rt *rt, t_obj **objs, char *line);
void				rt_parse_cylinder(t_rt *rt, t_obj **objs, char *line);
void				rt_parse_triangle(t_rt *rt, t_obj **objs, char *line);
void				rt_parse_move(t_rt *rt, char *line);
int					rt_parse_atoi(t_rt *rt, char *line);
double				rt_parse_atod(t_rt *rt, char *line);
void				rt_parse_info3(t_rt *rt, t_info3 *info3, char *line);
void				rt_parse_exit(t_rt *rt, int error_nb);
void				rt_parse_colorlimits(t_rt *rt, t_info3 *color);
void				rt_parse_veclimits(t_rt *rt, t_info3 *vec);
void				rt_parse_checks(t_rt *rt);

void				rt_image(t_rt *rt, t_cam **cams, int start);
void				rt_window(t_rt *rt, t_scn *scn, int start);
t_obj				*rt_image_getobjhit(t_scn *scn, t_hit *hit);
double				rt_image_tryhit(t_hit *hit, t_ray *ray, t_obj *obj);
t_info3				*rt_image_getcolor(t_scn *scn, t_amb *amb, t_hit *hit,
						t_obj *obj_hit);
void				rt_math_normalize(t_info3 *info3);
double				rt_math_cosine(t_info3 *info3a, t_info3 *info3b);
double				rt_math_lambertian(t_hit *hit, t_light *light);
double				rt_math_solution_sphere(double a, double b, double c);
double				rt_math_solution_cylinder(double a, double b, double c,
						int max_solution);
void				rt_info3_add(t_info3 *info3a, t_info3 *info3b);
void				rt_info3_mul(t_info3 *info3a, t_info3 *info3b);
t_info3				*rt_info3_diff(t_info3 *info3a, t_info3 *info3b);
double				rt_info3_dot(t_info3 *info3a, t_info3 *info3b);
void				rt_info3_limit(t_info3 *info3, double limit);
void				rt_image_rotation_x(t_info3 *info3, double alpha);
void				rt_image_rotation_y(t_info3 *info3, double beta);
void				rt_image_rotation_z(t_info3 *info3, double gamma);
t_info3				*rt_image_rotation_xyz(double x, double y, double z,
						t_info3 *vec);
void				rt_image_adjustray(t_rt *rt, t_scn *scn, t_cam *cam,
						t_ray *ray);
void				rt_image_getorigin(t_info3 *hit_ori, t_ray *ray,
						double solution);
double				rt_image_getdistance(t_info3 *hit_ori, t_info3 *light_ori);
t_info3				*rt_image_getintensity(t_info3 *color, double intens);
double				rt_image_rgbtoi(t_info3 *color);
double				rt_image_tryhit_sphere(t_ray *ray, t_obj *obj);
void				rt_image_gethitpoint_sphere(t_hit *hit, t_ray *ray,
						t_obj *obj_hit);
double				rt_image_tryhit_plane(t_ray *ray, t_obj *obj);
void				rt_image_gethitpoint_plane(t_hit *hit, t_ray *ray,
						t_obj *obj_hit);
t_info3				*rt_image_getnormal_plane(t_ray *ray, t_obj *obj);
double				rt_image_tryhit_square(t_hit *hit, t_ray *ray, t_obj *obj);
void				rt_image_gethitpoint_square(t_hit *hit, t_ray *ray,
						t_obj *obj_hit);
double				rt_image_tryhit_cylinder(t_hit *hit, t_ray *ray,
						t_obj *obj);
void				rt_image_gethitpoint_cylinder(t_hit *hit, t_ray *ray,
						t_obj *obj_hit);

int					rt_keys(int key, t_rt *rt);
int					rt_quit(t_rt *rt);
int					rt_loop(t_rt *rt);

void				rt_exit(int error_nb);

#endif
