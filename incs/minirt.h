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

# ifndef KEY_LNX_ESC
#  define KEY_LNX_ESC 65307
# endif

# ifndef KEY_LNX_C
#  define KEY_LNX_C 99
# endif

# ifndef KEY_MAC_ESC
#  define KEY_MAC_ESC 53
# endif

# ifndef KEY_MAC_C
#  define KEY_MAC_C 8
# endif

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
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
	int				line_nb;
	int				win_h;
	int				win_w;
	double			amb_intens;
	int				amb_r;
	int				amb_g;
	int				amb_b;
	struct s_cams	*cams;
	int				cams_total;
	int				cams_current;
	struct s_lights	*lights;
	struct s_objs	*objs;
	int				shad;
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_img	*img;
	int				loop;
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

typedef struct		s_shad
{
	t_cams			*ray;
	t_intersect		*intersect;
	t_vec			*diff;
	double			d_light2;
	double			d_obj2;
}					t_shad;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

void				rt_parse_line(t_scn *scn, char *line);
void				rt_parse_resolution(t_scn *scn, char *line);
void				rt_parse_camera(t_scn *scn, t_cams **cams, char *line);
void				rt_parse_light(t_scn *scn, t_lights **lights, char *line);
void				rt_parse_shadow(t_scn *scn, char *line);

void				rt_parse_sphere(t_scn *scn, t_objs **objs, char *line);

int					rt_parse_toint(t_scn *scn, char *line);
double				rt_parse_todouble(t_scn *scn, char *line);
void				rt_parse_vector(t_scn *scn, t_vec *vec, char *line);
void				rt_parse_color(t_scn *scn, t_color *color, char *line);

void				rt_parse_move(t_scn *scn, char *line);

void				rt_parse_checks(t_scn *scn);

t_vec				*rt_init_vector(void);
void				rt_fill_vector(t_scn *scn, t_vec *vec, char *line);
t_color				*rt_init_color(void);
void				rt_fill_color(t_scn *scn, t_color *color, char *line);

t_cams				*rt_init_camera(void);
int					rt_add_camera(t_cams **cams, t_cams *new_cam);
void				rt_clear_cameras(t_cams **cams);

t_lights			*rt_init_light(void);
int					rt_add_light(t_lights **lights, t_lights *new_light);
void				rt_clear_lights(t_lights **lights);

t_objs				*rt_init_object(void);
int					rt_add_object(t_objs **objs, t_objs *new_obj);
void				rt_clear_objects(t_objs **objs);

t_scn				*rt_init_scene(char *file_name);
void				rt_clear_scene(t_scn **scn,
						t_cams *cams, t_lights *lights, t_objs *objs);

t_intersect			*rt_init_intersection(void);
void				rt_clear_intersection(t_intersect **intersect);
t_delta				*rt_init_delta(double a, double b, double c);

t_shad				*rt_init_shadow(void);
void				rt_clear_shadow(t_shad **shad);

t_img				*rt_init_image(void);

void				rt_display_window(t_scn *scn);
void				rt_display_image(t_scn *scn);
void				rt_display_scene(t_scn *scn, t_cams **cams);
void				rt_display_object(t_scn *scn, t_cams *cams,
						t_intersect *intersect);
void				rt_display_pixel(t_scn *scn, t_cams *cam,
						t_intersect *intersect);

int					rt_display_shadow(t_scn *scn, t_intersect *intersect);

void				rt_display_adjustcam(t_scn *scn, t_cams *cam);
void				rt_display_getobjparams(t_scn *scn, t_objs *obj);
void				rt_display_getdiff(t_lights *light, t_intersect *intersect);
void				rt_display_pixintens(t_scn *scn, t_intersect *intersect);
int					rt_display_rgbtoi(int r, int g, int b);

void				rt_display_message(t_scn *scn);
int					rt_display_loop(t_scn *scn);

double				rt_math_intersect(t_cams *cam, t_objs *obj);
double				rt_math_dotproduct(t_vec *vec1, t_vec *vec2);
double				rt_math_solution(t_delta *delta);

double				rt_math_fov(double fov);
double				rt_math_norm2(t_vec *vec);
void				rt_math_normalize(t_vec *vec);
void				rt_math_pos_norm(t_scn *scn, t_cams *cam,
						t_intersect *intersect);

void				rt_exit_ko(int error_nb);
void				rt_exit_ko_scn(int error_nb, t_scn *scn);
void				rt_exit_ko_line(int error_nb, t_scn *scn, char *line);

int					rt_exit_ok(t_scn *scn);
int					rt_keys(int key, t_scn *scn);

#endif
