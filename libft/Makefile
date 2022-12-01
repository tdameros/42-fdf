NAME			=	libft.a

SRCS			=	srcs/char/ft_isalnum.c \
					srcs/char/ft_isalpha.c \
					srcs/char/ft_isascii.c \
					srcs/char/ft_isdigit.c \
					srcs/char/ft_isprint.c \
					srcs/char/ft_tolower.c \
					srcs/char/ft_toupper.c \
					srcs/int/ft_atoi.c \
					srcs/list/ft_lstadd_back.c \
					srcs/list/ft_lstadd_front.c \
					srcs/list/ft_lstclear.c \
					srcs/list/ft_lstdelone.c \
					srcs/list/ft_lstiter.c \
					srcs/list/ft_lstlast.c \
					srcs/list/ft_lstmap.c \
					srcs/list/ft_lstnew.c \
					srcs/list/ft_lstsize.c \
					srcs/mem/ft_bzero.c \
					srcs/mem/ft_calloc.c \
					srcs/mem/ft_memchr.c \
					srcs/mem/ft_memcmp.c \
					srcs/mem/ft_memcpy.c \
					srcs/mem/ft_memmove.c \
					srcs/mem/ft_memset.c \
					srcs/print/ft_printf.c \
					srcs/print/print_hexa.c \
					srcs/print/print_number.c \
					srcs/print/print_string.c \
					srcs/put/ft_putchar_fd.c \
					srcs/put/ft_putendl_fd.c \
					srcs/put/ft_putnbr_fd.c \
					srcs/put/ft_putstr_fd.c \
					srcs/string/ft_itoa.c \
					srcs/string/ft_split.c \
					srcs/string/ft_strchr.c \
					srcs/string/ft_strdup.c \
					srcs/string/ft_striteri.c \
					srcs/string/ft_strjoin.c \
					srcs/string/ft_strlcat.c \
					srcs/string/ft_strlcpy.c \
					srcs/string/ft_strlen.c \
					srcs/string/ft_strmapi.c \
					srcs/string/ft_strncmp.c \
					srcs/string/ft_strnstr.c \
					srcs/string/ft_strrchr.c \
					srcs/string/ft_strtrim.c \
					srcs/string/ft_substr.c \
					srcs/file/get_next_line.c \
					srcs/file/get_next_line_utils.c

DIR_INCS		=	incs/
DIR_BUILD		=	.build/
OBJS			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(SRCS))
DEPS			=	$(patsubst %.c, $(DIR_BUILD)%.d, $(SRCS))
DEPS_FLAGS		=	-MMD -MP
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
AR				= 	ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean :
		$(RM) $(DIR_BUILD)

fclean : clean
		$(RM) $(NAME)

re : fclean all

-include $(DEPS)

$(DIR_BUILD)%.o : %.c
		mkdir -p $(shell dirname $@)
		$(CC) $(CFLAGS) $(DEPS_FLAGS) -I $(DIR_INCS) -c $< -o $@

.PHONY: all clean fclean re
