NAME = miniRT

CC = clang
FLAGC = -Wall -Wextra -Werror
FLAGL = -lm -lbsd -lX11 -lXext -Llibs -lft

SRCS_DIR = srcs/
SRCS = srcs/main.c
SRCS += srcs/1_parse/rt_parse_1_start.c
SRCS += srcs/1_parse/rt_parse_2_objects.c
SRCS += srcs/1_parse/rt_parse_3_utils.c
SRCS += srcs/1_parse/rt_parse_4_checks.c
SRCS += srcs/2_structs/rt_structs_1_base.c
SRCS += srcs/2_structs/rt_structs_2_camera.c
SRCS += srcs/2_structs/rt_structs_3_light.c
SRCS += srcs/2_structs/rt_structs_4_object.c
SRCS += srcs/2_structs/rt_structs_5_scene.c
SRCS += srcs/2_structs/rt_structs_6_math.c
SRCS += srcs/2_structs/rt_structs_7_image.c
SRCS += srcs/3_display/rt_display_1_start.c
SRCS += srcs/3_display/rt_display_2_utils_1.c
SRCS += srcs/3_display/rt_display_2_utils_2.c
SRCS += srcs/4_math/rt_math_1_intersect.c
SRCS += srcs/4_math/rt_math_2_utils.c
SRCS += srcs/5_exit_and_keys/rt_exit_1_ko.c
SRCS += srcs/5_exit_and_keys/rt_exit_2_ok_and_keys.c
SRCS += srcs/get_next_line/get_next_line.c
SRCS += srcs/get_next_line/get_next_line_utils.c

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
