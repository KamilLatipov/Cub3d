#include "../include/cub3d.h"

int	get_resolution(t_info *list, char *line)
{
	int i;
    int m;

    m = 0;
	i = 0;
	if (list->res_x != 0 || list->res_y != 0)
		return (0); //Обработать ошибку
	list->res_x = ft_atoi(&line[i], &i);
	list->res_y = ft_atoi(&line[i], &i);
	if (list->res_x > 1080)
		mlx_get_screen_size(&list->res_x, &m);
	if (list->res_y > 900)
		mlx_get_screen_size(&m, &list->res_y);
	skip_space(line, &i);
	if (list->res_x <= 0 || list->res_y <= 0 || line[i] != '\0')
		return (0);//Обработать ошибку
	return (1);
}
