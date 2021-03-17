#include <fcntl.h>
#include "include/cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int    my_mlx_pixel_take(t_data *data, int x, int y)
{
    char *addr;
    unsigned int color;


    addr = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    color = *(unsigned int*)addr;
    return (color);
}

void 	parse_file(t_info *list, char *line, t_list **head)
{
	int i;

    list->line = line;
	i = 0;
	skip_space(line, &i);
	if (is_map(&line[i]) || (list->map_exist && line[i] != '\0'))
		get_map(list, &line[0], head);
	else if (line[i] == 'R' && line[i + 1] == ' ' )
		get_resolution(list, &line[i + 1]);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_wall_texture(list, 'N', line, & i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_wall_texture(list, 'S', line, & i);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		get_wall_texture(list, 'W', line, & i);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		get_wall_texture(list, 'E', line, & i);
	//else if (line[i] == 'S')
	//	get_sprite_testure(list, line);
	else if (line[i] == 'F' && line[i + 1] == ' ')
        get_color(&list->floor, &line[i]);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		get_color(&list->clng, &line[i]);
}

void	ft_init_player(t_info *list)
{
	list->dirX = -1.0;
	list->dirY = 0.0;
	list->planeX = 0.0;
	list->planeY = 0.66;
}

int     main(int arg, char **argv)
{
	t_info *list;
	int ret;
	char *line;
    t_list  *head;
    t_mlx	mlx;

    arg = 0;
    list = calloc(1, sizeof(t_info));
    head = NULL;
	mlx.mlx = mlx_init();
    list->mlx = &mlx;
	list->fd = open(argv[1], O_RDONLY); //Обработать ошибку, если fd < 0
    if (list->fd <= 0)
        return (0);
	while ((ret = get_next_line(list->fd, &line)))
	{
        if (ret == -1)
            return (0);
		parse_file(list, line, &head);
    }
	close(list->fd);
	ft_lstadd_back(&head, ft_lstnew(line));
    list->mlx->win = mlx_new_window(mlx.mlx, list->res_x, list->res_y, "Cub3D");
	list->map = fill_map_array(&head, ft_lstsize(head), list);
	ft_init_player(list);
    draw_screen(list, list->mlx);
    mlx_hook(list->mlx->win, 2, 1L<<0, key_press, list);
    mlx_loop(mlx.mlx);
}

