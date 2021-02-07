#include <fcntl.h>
#include "include/cub3d.h"

void 	parse_file(t_list *list, char *line)
{
	int i;

	if (line[i] == 'R')
		get_res(list, line);
	else if (line[i] == 'N')
	else if (line[i] == 'S' && line[i] == 'O')
	else if (line[i] == 'W')
	else if (line[i] == 'E')
	else if (line[i] == 'S')
	else if (line[i] == 'F')
		get_color(list->floor);
	else if (line[i] == 'C')
		get_color(list->clng);
	else if (line[i] == '')
}

int     main(int arg, char **argv)
{
	t_list *list;
	int fd;
	int i;
	int ret;
	char *line;

	fd = open(argv[1], 0_RDONLY);
	while (ret = get_next_line(fd, &line))
	{
		parse_file(list, line);
	}
	if (ret == -1)
	{
		//Обработать ошибку
	}
    return (0);
}

