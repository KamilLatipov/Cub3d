#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
    int         width;
    int         height;
}               t_data;

typedef strcut	s_sprt	{
	double 		x;
	double 		y;
	double 		dist;
}				t_sprt;

typedef struct  s_mlx {
	void        *mlx;
	void 		*win;
}               t_mlx;

typedef struct	s_sprite
{
	double		transformy;
	int			spritescreenx;
	int			spritew;
	int			spriteh;
	int			drawstartx;
	int			drawendx;
	int			drawstarty;
	int			drawendy;
}				t_sprite;

typedef struct	s_info
{
    float deltaDistX;
	float deltaDistY;
	float rayDirX;
	float rayDirY;
	float sideDistX;
	float sideDistY;
	int stepX;
	int stepY;
	int side;
	float perpWallDist;
    float lineHeight;
    float posX;
	float posY;
	float dirX;
	float dirY;
	float planeX;
	float planeY;
    int map_exist;
    int floor;
    int clng;
    int res_x;
    int res_y;
    char **map;
    int plr;
    int	fd;
    int max_size;
    int max_height;
    char *line;
    t_sprt	*sprt;
    int sprts_number;
    t_data  n;
    t_data  w;
    t_data  s;
    t_data  e;
	t_mlx	*mlx;
	t_data	*img;
}				t_info;

int		get_next_line(int fd, char **line);
//int		ft_strlen(const char *s);
int 	main(int fd, char *argv[]);
void 	parse_file(t_info *list, char *line,t_list **head);
void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 	is_map(char *line);
void	skip_space(char *line, int *i);
int     get_color(int *color, char *line);
int 	get_map(t_info *list, char *line, t_list **head);
int     get_resolution(t_info *list, char *line);
char**	fill_map_array(t_list **head, int size, t_info *list);
void    put_pixel_square(int i, int j, t_data *img);
void	init_window(t_info *list);
void	ft_init_player(t_info *list);
void    draw_screen(t_info *list, t_mlx *mlx);
int     key_press(int key, t_info *list);
void    find_wall_hit(t_info *list, int *mapX,int *mapY);
int		get_wall_texture(t_info *list, char side, char *line, int *i);
int		check_name(char *arg, char *ext);
unsigned int my_mlx_pixel_take(t_data *data, int x, int y);
void    handle_error(char **map, t_info *list, char *str);
void 	handle_sprt(t_info *list);
void	draw_sprites(t_info *list);

#endif
