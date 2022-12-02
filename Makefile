#*******************************  VARIABLES  **********************************#

NAME			=	fdf

# --------------- FILES --------------- #

LIST_SRCS		=	main.c \
					parser.c \
					parser_utils.c \
					drawer.c \
					drawer_utils.c \
					libx.c \
					errors.c \
					utils.c

# ------------ DIRECTORIES ------------ #

DIR_BUILD		=	.build/
DIR_SRCS 		= 	srcs/
DIR_HEADERS		=	includes/
DIR_LIBFT		=	libft/

# ------------- SHORTCUTS ------------- #

OBJS			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))
DEPS			=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRCS))
SRCS			=	$(addprefix $(DIR_SRCS),$(LIST_SRCS))

# ------------ COMPILATION ------------ #

CFLAGS			=	-Wall -Wextra -Werror -O3
DEPS_FLAGS		=	-MMD -MP

# -------------  COMMANDS ------------- #

RM				=	rm -rf
MKDIR			=	mkdir -p

# -------------  MLX ------------- #

OS				= $(shell uname -s)

ifeq ($(OS), Linux)
	DIR_MLX		=	minilibx_linux/
	MLX_FLAGS	=	-lXext -lX11 -lm
endif
ifeq ($(OS), Darwin)
	DIR_MLX		=	minilibx_macos/
	MLX_FLAGS	=	-framework OpenGL -framework AppKit
endif

#***********************************  RULES  **********************************#

.PHONY: all
all:			$(NAME)

# ---------- VARIABLES RULES ---------- #

$(NAME):		mlx libft $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(DIR_LIBFT) -lft -I $(DIR_MLX) -L $(DIR_MLX) -lmlx $(MLX_FLAGS)

# ---------- COMPILED RULES ----------- #

-include $(DEPS)

$(DIR_BUILD)%.o: %.c
				mkdir -p $(shell dirname $@)
				$(CC) $(CFLAGS) $(DEPS_FLAGS) -I $(DIR_MLX) -I $(DIR_HEADERS) -c $< -o $@

.PHONY: mlx
mlx:
	$(MAKE) -C $(DIR_MLX)

.PHONY: libft
libft:
	$(MAKE) -C $(DIR_LIBFT)

.PHONY: clean
clean:
				$(MAKE) -C $(DIR_LIBFT) clean
				$(MAKE) -C $(DIR_MLX) clean
				$(RM) $(DIR_BUILD)

.PHONY: fclean
fclean: clean
				$(MAKE) -C $(DIR_LIBFT) fclean
				$(RM) $(NAME)

.PHONY: re
re:				fclean
				$(MAKE) -C ./
