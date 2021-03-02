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
}               t_data;

typedef struct  s_mlx {
	void        *mlx;
	void 		*win;
}               t_mlx;

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
char**	fill_map_array(t_list **head, int size);
void    put_pixel_square(int i, int j, t_data *img);
void	init_window(t_info *list);
void	ft_init_player(t_info *list);
void    draw_screen(t_info *list, t_mlx *mlx);
int     key_press(int key, t_info *list);
void    find_wall_hit(t_info *list, int *mapX,int *mapY);

#endif
