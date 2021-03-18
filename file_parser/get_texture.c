#include "../include/cub3d.h"

static void choose_side(t_info *list, char side, t_data tex)
{
    if (side == 'N')
        list->n = tex;
    else if (side == 'S')
        list->s = tex;
    else if (side == 'W')
        list->w = tex;
    else if (side == 'E')
        list->e = tex;
    else if (side == 'C')
        list->sprt_text = tex;
}

static int ft_xpm(t_info *list, char side, char *file)
{
	int		fd;
    t_data  tex;

	if (check_name(file, "xpm") == 0)
		return (-1);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	if ((tex.img = mlx_xpm_file_to_image(list->mlx->mlx, file, &tex.width, &tex.height)) == NULL)
        return (-1);
	tex.addr = mlx_get_data_addr(tex.img, &tex.bits_per_pixel, &tex.line_length, &tex.endian);
    choose_side(list, side, tex);
	return (0);
}

int		get_wall_texture(t_info *list, char side, char *line, int *i)
{
	char	*file;
	int		j;

	(*i) += 2;
	skip_space(line, i);
	j = *i;
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	if (!(file = malloc(sizeof(char) * (*i - j + 1))))
		return (-8);
	*i = j;
	j = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
		file[j++] = line[(*i)++];
	file[j] = '\0';
	j = ft_xpm(list, side, file);
	free(file);
	return (j == -1 ? -9 : 0);
}