#include <fcntl.h>
#include "include/cub3d.h"
#include "libft/libft.h"

void 	parse_file(t_list *list, char *line, char *map)
{
	int i;

	i = 0;
	skip_space(line, &i);
	if (is_map(line[i]) || (list->map_exist && line[i] != '\0')
		get_map(list, line[i], map);
	else if (line[i] == 'R' && line[i + 1] == ' ' )
		get_resolution(list, line[i + 1]);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_wall_texture(list, line);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_wall_texture(list, line);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		get_wall_texture(list, line);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		get_wall_texture(list, line);
	else if (line[i] == 'S')
		get_sprite_testure(list, line);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		get_color(&list->floor, line[i]);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		get_color(&list->clng, line[i]);
	return (0);
}

int     main(int arg, char **argv)
{
	t_list *list;
	int fd;
	int ret;
	char *line;
	char *map_string;

	map_string = malloc(sizeof(char) * 1);
	map_string[1] = '\0';
	fd = open(argv[1], 0_RDONLY); //Обработать ошибку, если fd < 0
	while (ret = get_next_line(fd, &line))
	{
		parse_file(list, line, map_string);
		free(line);
	}
	close(fd);
	if (ret == -1)
	{
		//Обработать ошибку
	}
    return (0);
}

