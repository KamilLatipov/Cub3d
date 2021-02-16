#include "../include/cub3d.h"

int	get_color(int *color, char *line)
{
	int r;
	int g;
	int b;
	int i;

	i = 0;
	if (*color)
		return (0); //Обработать ошибку
	r = ft_atoi(&line[i], &i);
	i++;
	g = ft_atoi(&line[i], &i);
	i++;
	b = ft_atoi(&line[i], &i);
	i++;
	skip_space(line, &i);
    *color = 2;
	if (r > 255 || r < 0
		|| g > 255 || g < 0 || b > 255 || b < 0 || line[i] != '\0')
		return (0); //Обработать ошибку
	//*color =  r << 16 | g << 8 | b;
	return (1);
}
