#include "../include/cub3d.h"

int	get_resolution(t_info *list, char *line)
{
	int i;

	i = 0;
	if (list->res_x != 0 || list->res_y != 0)
		return (0); //Обработать ошибку
	list->res_x = ft_atoi(&line[i], &i);
	list->res_y = ft_atoi(&line[i], &i);
	if (list->res_x > 1080)
		list->res_x = 1080;
	if (list->res_y > 900)
		list->res_y = 900;
	skip_space(line, &i);
	if (list->res_x <= 0 || list->res_y <= 0 || line[i] != '\0')
		return (0);//Обработать ошибку
	return (1);
}
