NAME = miniRT

CC = clang
FLAGC = -Wall -Wextra -Werror
FLAGL = -lm -lbsd -lX11 -lXext -Llibs -lft

SRCS_DIR = srcs/
SRCS = srcs/minirt.c
SRCS += srcs/get_next_line.c
SRCS += srcs/1_struct/rt_struct_1_file.c
SRCS += srcs/1_struct/rt_struct_2_info3.c
SRCS += srcs/1_struct/rt_struct_3_ambiance.c
SRCS += srcs/1_struct/rt_struct_4_camera.c
SRCS += srcs/1_struct/rt_struct_5_light.c
SRCS += srcs/1_struct/rt_struct_6_object.c
SRCS += srcs/1_struct/rt_struct_7_scene.c
SRCS += srcs/1_struct/rt_struct_8_ray_hit.c
SRCS += srcs/1_struct/rt_struct_9_image.c
SRCS += srcs/2_parse/rt_parse_1_start.c
SRCS += srcs/2_parse/rt_parse_2_element.c
SRCS += srcs/2_parse/rt_parse_3_object.c
SRCS += srcs/2_parse/rt_parse_4_utils_1.c
SRCS += srcs/2_parse/rt_parse_4_utils_2.c
SRCS += srcs/3_image/rt_image_1_start.c
SRCS += srcs/3_image/rt_image_2_hit.c
SRCS += srcs/3_image/rt_image_3_color.c
SRCS += srcs/3_image/rt_image_4_math.c
SRCS += srcs/3_image/rt_image_5_info3.c
SRCS += srcs/3_image/rt_image_6_rotation.c
SRCS += srcs/3_image/rt_image_7_utils.c
SRCS += srcs/3_image/rt_image_object/rt_image_11_sphere.c
SRCS += srcs/3_image/rt_image_object/rt_image_12_plane.c
SRCS += srcs/3_image/rt_image_object/rt_image_13_square.c
SRCS += srcs/3_image/rt_image_object/rt_image_14_cylinder.c
SRCS += srcs/3_image/rt_image_object/rt_image_15_triangle.c
SRCS += srcs/4_keys/rt_keys.c
SRCS += srcs/5_exit/rt_exit.c

OBJS = ${SRCS:.c=.o}

INCS_DIR = incs/

LIBS_DIR = libs/

LIBX_DIR = libs/minilibx/
LIBX1 = libmlx.a
LIBX2 = libmlx_Linux.a
LIBXH = mlx.h

LIBFT_DIR = libs/libft/
LIBFT = libft.a
LIBFTH = libft.h

$(NAME): $(LIBX1) $(LIBFT) $(OBJS)
	@$(CC) $(FLAGC) $(OBJS) $(LIBS_DIR)$(LIBX1) $(LIBS_DIR)$(LIBX2) $(FLAGL) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGC) -I $(INCS_DIR) -c $? -o $@
	@echo "Compiling [$?] ... OK"

$(LIBX1):
	@make -C $(LIBX_DIR)
	@cp $(LIBX_DIR)$(LIBX1) $(LIBS_DIR)
	@cp $(LIBX_DIR)$(LIBX2) $(LIBS_DIR)
	@cp $(LIBX_DIR)$(LIBXH) $(INCS_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)$(LIBFT) $(LIBS_DIR)
	@cp $(LIBFT_DIR)$(LIBFTH) $(INCS_DIR)

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f $(LIBS_DIR)$(LIBX1) $(LIBS_DIR)$(LIBX2) $(LIBS_DIR)$(LIBFT)
	@rm -f $(INCS_DIR)$(LIBXH) $(INCS_DIR)$(LIBFTH)

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
