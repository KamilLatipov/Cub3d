#include "../include/cub3d.h"

int	get_resolution(t_info *list, char *line)
{
	int i;
	int ret_val;

	i = 0;
	if (list->res_x != 0 || list->res_y != 0)
		return (0); //Обработать ошибку
	list->res_x = ft_atoi(&line[i], &i);
	list->res_y = ft_atoi(&line[i], &i);
	if (list->res_x > 2560)
		list->res_x = 2560;
	if (list->res_y > 1400)
		list->res_y = 1400;
	skip_space(line, &i);
	if (list->res_x <= 0 || list->res_y <= 0 || line[i] != '\0')
		return (0);//Обработать ошибку
	return (1);
}
