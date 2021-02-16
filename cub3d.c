#include <fcntl.h>
#include "include/cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void 	parse_file(t_info *list, char *line, t_list **head)
{
	int i;

	i = 0;
	skip_space(line, &i);
	if (is_map(&line[i]) || (list->map_exist && line[i] != '\0'))
		get_map(list, &line[i], head);
	else if (line[i] == 'R' && line[i + 1] == ' ' )
		get_resolution(list, &line[i + 1]);
	//else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
	//	get_wall_texture(list, line);
	//else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
	//	get_wall_texture(list, line);
	//else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
	//	get_wall_texture(list, line);
	//else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
	//	get_wall_texture(list, line);
	//else if (line[i] == 'S')
	//	get_sprite_testure(list, line);
	else if (line[i] == 'F' && line[i + 1] == ' ')
        get_color(&list->floor, &line[i]);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		get_color(&list->clng, &line[i]);
}

int     main(int arg, char **argv)
{
	t_info *list;
	int fd;
	int ret;
	char *line;
	char *map_string;
	void    *mlx;
	void    *mlx_win;
    t_data  img;
    t_list *head;

	mlx = mlx_init();
    arg = 0;
    list = malloc(sizeof(t_info));
    ft_bzero(list, sizeof(t_info));
    head = NULL;
	map_string = malloc(sizeof(char) * 1);
	map_string[1] = '\0';
	fd = open(argv[1], O_RDONLY); //Обработать ошибку, если fd < 0
    if (fd <= 0)
    {
        return (0);
    }
	while ((ret = get_next_line(fd, &line)))
	{
        if (ret == -1)
            return (0);
		if (is_map(&line[i]) || (list->map_exist && line[i] != '\0'))
		{
			if (!is_map(line))
				return (0); //Обработать ошибку
			list->map_exist = 1;
			ft_lstadd_back(&head, ft_lstnew(line));
		}
		else
			parse_file(list, line, &head);
		free(line);
	}
	ft_lstadd_back(&head, ft_lstnew(line));
    printf("size = %i\n", ft_lstsize(head));
	list->map = fill_map_array(&head, ft_lstsize(head));
	close(fd);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, list->res_x, list->res_y, "Hello world!");
	img.img = mlx_new_image(mlx, list->res_x, list->res_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
    my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//mlx_loop(mlx);
	if (ret == -1)
		//Обработать ошибку
    return (0);
}

