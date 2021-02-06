NAME      = cub3d

CC        = gcc

FLAGS     = -Wall -Werror -Wextra

MLXFLAGS  = -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADERS   = include/

MLX       = mlx

MLXNAME   = $(MLX)/libmlx.a

LIBFT     = libft/

LIBFTNAME = $(LIBFT)/libft.a

OBJS     = $(SRC:.c=.o)

SRC      = cub3d.c

all:    $(NAME)

$(MLXNAME):
		$(MAKE) -C $(MLX)

$(LIBFTNAME):
		$(MAKE) -C $(LIBFT)

%.o: %.c
		$(CC) $(FLAGS) -c $< -I $(HEADERS) -o $@

$(NAME): $(MLXNAME) $(LIBFTNAME) $(OBJS)
		$(CC) -o $@ $^ $(MLXFLAGS)

clean:
		rm -f $(OBJS)
		$(MAKE) clean -C $(MLX)
		$(MAKE) clean -C $(LIBFT)

fclean: clean
		rm -f $(NAME)
		$(MAKE) fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

