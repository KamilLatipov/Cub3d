NAME      = cub3d

CC        = gcc

FLAGS     = -Wall -Werror -Wextra

MLXFLAGS  = -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADERS   = include/

MLX       = mlx

MLXNAME   = libmlx.dylib

LIBFT     = libft/

LIBFTNAME = libft.a

OBJS     = $(SRC:.c=.o)

SRC      = cub3d.c

all:    $(NAME)

$(MLXNAME):
        $(MAKE) -c $(MLX)

$(LIBFTNAME):
        $(MAKE) -c $(LIBFT)

%.o: %.c
        $(CC) $(FLAGS) -c $< -I $(HEADERS) -o $@

$(NAME): $(MLXNAME) $(LIBFTNAME) $(OBJS)
        $(CC) -o $@ $^ $(MLXFLAGS)

.clean:
        rm -f $(OBJS)
        $(MAKE) clean -c $(MLX)
        $(MAKE) clean -c $(LIBFT)

.fclean: clean
        rm -f $(NAME)
        $(MAKE) fclean -c $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

