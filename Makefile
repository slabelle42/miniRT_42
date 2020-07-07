NAME = miniRT

CC = clang
FLAGC = -Wall -Wextra -Werror
FLAGL = -lm -lbsd -lX11 -lXext -Llibs -lft

MAIN = minirt.c

SRC_DIR = srcs/
SRC = srcs/rt_color.c
SRC += srcs/rt_display.c
SRC += srcs/rt_object.c
SRC += srcs/rt_vector.c

INC_DIR = incs/
LIBXH = mlx.h
LIBFTH = libft.h

LIB_DIR = libs/
LIBX_DIR = libs/minilibx/
LIBX1 = libmlx.a
LIBX2 = libmlx_Linux.a
LIBFT_DIR = libs/libft/
LIBFT = libft.a

$(NAME):
	@make -C $(LIBX_DIR)
	@cp $(LIBX_DIR)$(LIBX1) $(LIB_DIR)
	@cp $(LIBX_DIR)$(LIBX2) $(LIB_DIR)
	@cp $(LIBX_DIR)$(LIBXH) $(INC_DIR)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)$(LIBFT) $(LIB_DIR)
	@cp $(LIBFT_DIR)$(LIBFTH) $(INC_DIR)
	@$(CC) $(SRC_DIR)$(MAIN) $(SRC) $(LIB_DIR)$(LIBX1) $(LIB_DIR)$(LIBX2) $(FLAGL) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(LIB_DIR)$(LIBX1) $(LIB_DIR)$(LIBX2) $(INC_DIR)$(LIBXH)
	@rm -f $(LIB_DIR)$(LIBFT) $(INC_DIR)$(LIBFTH)

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
