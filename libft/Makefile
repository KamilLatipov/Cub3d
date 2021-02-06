SRC		= ft_atoi.c	ft_isdigit.c ft_memmove.c \
        ft_strlcpy.c ft_tolower.c ft_bzero.c \
        ft_isprint.c \
        ft_memset.c	\
        ft_strlen.c	\
        ft_toupper.c \
        ft_calloc.c	\
        ft_memccpy.c \
        ft_strchr.c	\
        ft_strncmp.c \
        ft_isalnum.c \
        ft_memchr.c	\
        ft_strnstr.c \
        ft_isalpha.c \
        ft_memcmp.c	\
        ft_strrchr.c \
        ft_isascii.c \
        ft_memcpy.c	\
        ft_strlcat.c \
        ft_substr.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_split.c \
        ft_strdup.c \
        ft_itoa.c \
        ft_strmapi.c \
        ft_putchar_fd.c \
        ft_putstr_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \

.PHONY:		all clean fclean re

NAME	=   libft.a

CFLAGS	=  -Wall -Wextra -Werror

CC		=  gcc

OBJS	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
		-rm -f $(OBJS)

fclean: clean
		-rm -f $(NAME)

re:		fclean all