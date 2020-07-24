NAME = libft.a

FLAG = -Wall -Wextra -Werror

EXE = libft
MAIN = main.c

# [ int ]
SRC =	ft_atoi.c
SRC +=	ft_itoa.c	
# [ char ]
SRC +=	ft_isalnum.c
SRC +=	ft_isalpha.c
SRC +=	ft_isascii.c
SRC +=	ft_isdigit.c
SRC +=	ft_isprint.c
SRC +=	ft_tolower.c
SRC +=	ft_toupper.c
# [ str ]
SRC +=	ft_split.c
SRC +=	ft_strchr.c
SRC +=	ft_strdup.c
SRC +=	ft_strend.c
SRC +=	ft_strjoin.c
SRC +=	ft_strlcat.c
SRC +=	ft_strlcpy.c
SRC +=	ft_strlen.c
SRC +=	ft_strmapi.c
SRC +=	ft_strncmp.c
SRC +=	ft_strnstr.c
SRC +=	ft_strrchr.c
SRC +=	ft_strtrim.c
SRC +=	ft_substr.c
# [ mem ]
SRC +=	ft_bzero.c
SRC +=	ft_calloc.c
SRC +=	ft_memalloc.c
SRC +=	ft_memccpy.c
SRC +=	ft_memchr.c
SRC +=	ft_memcmp.c
SRC +=	ft_memcpy.c
SRC +=	ft_memmove.c
SRC +=	ft_memset.c
# [ put ]
SRC +=	ft_putchar_fd.c
SRC +=	ft_putendl_fd.c
SRC +=	ft_putnbr_fd.c
SRC +=	ft_putstr_fd.c
# [ lst ]
ifeq ($(MAKECMDGOALS), bonus)
SRC +=	ft_lstadd_back.c
SRC +=	ft_lstadd_front.c
SRC +=	ft_lstclear.c
SRC +=	ft_lstdelone.c
SRC +=	ft_lstiter.c
SRC +=	ft_lstlast.c
SRC +=	ft_lstmap.c
SRC +=	ft_lstnew.c
SRC +=	ft_lstsize.c
endif

# [ obj ]
OBJ_DIR = obj/
OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $?
	@ranlib $@
	@echo "Indexing ... OK"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $@
	@echo "Creating [$@] directory ... OK"

$(OBJ_DIR)%.o: %.c
	@gcc $(FLAG) -I. -c $? -o $@
	@echo "Compiling [$?] ... OK"

bonus: $(NAME)

exe:
	@gcc -o $(EXE) $(MAIN) -L. -lft
	@echo "Creating executable ... OK"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning ... OK"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(EXE)

re: fclean all

.PHONY: all bonus exe clean fclean re
