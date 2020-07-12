NAME = miniRT

CC = clang
FLAGC = -Wall -Wextra -Werror
FLAGL = -lm -lbsd -lX11 -lXext -Llibs -lft

SRCS_DIR = srcs/
SRCS = srcs/main.c
SRCS += srcs/rt_1_parse.c
SRCS += srcs/rt_2_struct_1_base.c
SRCS += srcs/rt_2_struct_2_camera.c
SRCS += srcs/rt_2_struct_3_light.c
SRCS += srcs/rt_2_struct_4_object.c
SRCS += srcs/rt_2_struct_5_scene.c
SRCS += srcs/rt_2_struct_6_math.c
SRCS += srcs/rt_3_display_1_window.c
SRCS += srcs/rt_3_display_2_utils.c
SRCS += srcs/rt_4_math.c
SRCS += srcs/rt_5_color.c

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
