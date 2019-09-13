NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_PATH = ./srcs/
OBJS_PATH = ./objects/

SRCS_NAME = ft_atoi.c \
			ft_bzero.c \
			ft_clamp.c \
			ft_countword.c \
			ft_error.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_iswhite.c \
			ft_itoa.c \
			ft_lenint.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_max.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_print_words_tables.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_range.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strjoinfree.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strsubfree.c \
			ft_strtrim.c \
			ft_swap.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c \
			ft_numberlen.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(subst $(SRCS_PATH), $(OBJS_PATH), $(SRCS:.c=.o))
INCLUDES = includes/

all:	$(NAME)

$(NAME):    $(OBJS)
	@ar rc $(NAME) $(OBJS) && ranlib $(NAME)

$(OBJS) : | $(OBJS_PATH)

$(OBJS_PATH):
	@mkdir objects

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c includes/libft.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	@/bin/rm -rf objects/

fclean:	clean
	@/bin/rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
