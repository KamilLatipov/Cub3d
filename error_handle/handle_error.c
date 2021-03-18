#include "../include/cub3d.h"

void    handle_error(char **map, t_info *list, char *str)
{
    map = 0;
    list->clng = 0;
    write(1, "Error : ", 8);
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    exit(0);
}