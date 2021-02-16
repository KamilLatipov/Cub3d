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

typedef struct	s_info
{
    int map_exist;
    int floor;
    int clng;
    int res_x;
    int res_y;
    char **map;
}				t_info;

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

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

#endif
