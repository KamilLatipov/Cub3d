#include "../include/cub3d.h"

static int find_sprts_number(char **map)
{
	int		count;
	int		y;
	int 	x;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '2')
				count += 1;
			x++;
		}
		y++;
	}
	return (count);
}

static void	sort_sprts_bubble(t_info *list, double *distances)
{
	int		i;
	double	dist_swap;
	t_sprt	coord_swap;

	i = 1;
	while (i < list->sprts_number)
	{
		if (distances[i - 1] < distances[i])
		{
			dist_swap = distances[i - 1];
			distances[i - 1] = distances[i];
			distances[i] = dist_swap;
			coord_swap = list->sprt[i - 1];
			list->sprt[i - 1] = list->sprt[i];
			list->sprt[i] = coord_swap;
			i = 1;
		}
		else
			i++;
	}
}

static void	fill_sprites_array(t_info *list)
{
	t_sprt	*s_index;
	int		x;
	int 	y;

	list->sprts_number = find_sprts_number(list->map);
	if (!(list->sprt = (t_sprt*)malloc(sizeof(t_sprt) * list->sprts_number)))
		handle_error(NULL, list, "malloc fail");
	s_index = list->sprt;
	y = 0;
	while (list->map[y])
	{
		x = 0;
		while (list->map[y][x])
		{
			if (list->map[y][x])
			{
				s_index->x = (double)((x) + 0.5);
				s_index->y = (double)((y) + 0.5);
				s_index++;
			}
			x++;
		}
		y++;
	}
}

static void sort_sprts_array(t_info *list)
{
	int		i;
	double	*distances;

	i = 0;
	if (!(distances = (double*)malloc(sizeof(double) * list->sprts_number)))
		return ;
	while (i < list->sprts_number)
	{
		distances[i] = ((list->posX - list->sprt[i].x) *
						(list->posX - list->sprt[i].x) +
						(list->posY - list->sprt[i].y) *
						(list->posY - list->sprt[i].y));
		i++;
	}
	sort_sprts_bubble(list, distances);
	free(distances);
}

void 	handle_sprt(t_info *list)
{
    fill_sprites_array(list);
    sort_sprts_array(list);
}