#include <fcntl.h>
#include "include/cub3d.h"
#include "libft/libft.h"

void 	parse_file(t_list *list, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'R' && line[i + 1] == ' )
		get_resolution(list, line[1]);
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
		get_color(&list->floor, line);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		get_color(&list->clng, line);
	return (0);
}

int     main(int arg, char **argv)
{
	t_list *list;
	int fd;
	int i;
	int ret;
	char *line;

	fd = open(argv[1], 0_RDONLY); //Обработать ошибку, если fd < 0
	while (ret = get_next_line(fd, &line))
	{
		parse_file(list, line);
		free(line);
	}
	close (fd);
	if (ret == -1)
	{
		//Обработать ошибку
	}
    return (0);
}

