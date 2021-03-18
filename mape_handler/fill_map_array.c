#include "../include/cub3d.h"

static int find_plr(t_info *list, char *map, int x)
{
    int y;

    y = 0;
    while (map[y])
    {
        if (map[y] == 'N' || map[y] == 'W' || map[y] == 'E' || map[y] == 'S')
        {
            if (list->plr)
                return (0);
            list->posY = y + 0.5; 
            list->posX = x + 0.5;
            list->plr = 1;
        }
        y++;
    }
    return (1);
}

static char *fill_max_str(char *line, t_info *list)
{
    char *str;
    int i;

    i = 0;
    str = (char *)malloc(sizeof(char) * list->max_size + 1);
    while (i < list->max_size)
        str[i++] = ' ';
    str[i] = '\0';
    i = 0;
    while (line[i])
    {
        str[i] = line[i];
        i++;
    }
    return (str);
}

static  int check_map(char **map, t_info *list, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (0);
	if (map[y][x] == ' ' || ((y == 0 || x == 0 || x == list->max_size - 1
							  || y == list->max_height - 1) && map[y][x] != 1))
                            handle_error(map, list, "map is not closed");
	if (map[y][x] == '0' || map[y][x] == '2')
		map[y][x] = 'x';
	if (x < list->max_size - 1)
		check_map(map, list, x + 1, y);
	if (x > 0)
		check_map(map, list, x - 1, y);
	if (y < list->max_height - 1)
		check_map(map, list, x, y + 1);
	if (y > 0)
		check_map(map, list, x, y - 1);
	if (x < list->max_size - 1 && y < list->max_height - 1)
		check_map(map, list, x + 1, y + 1);
	if (x < list->max_size - 1 && y > 0)
		check_map(map, list, x + 1, y - 1);
	if (x > 0 && y > 0)
		check_map(map, list, x - 1, y - 1);
	if (x > 0 && y < list->max_height - 1)
		check_map(map, list, x - 1, y + 1);
	return (0);
}

static void copy_map(char **map, int i, t_info *list)
{
	char *map_check[i];
	int j;

	j = 0;
	while (j < i)
	{
		map_check[j] = ft_strdup(map[j]);
		j++;
	}
	map_check[j] = NULL;
    check_map(map_check, list, list->posY, list->posX);
}

char **fill_map_array(t_list **head, int size, t_info *list)
{
	char 	**map;
	int		  i;
	t_list	*tmp;

	map = malloc((size + 1) * sizeof(char *));
	ft_bzero(map, sizeof(size + 1));
	i = 0;
	tmp = *head;
	while (tmp)
	{
		map[i++] = fill_max_str(tmp->content, list);
        if (tmp->content)
        {
            free(tmp->content);
            tmp->content = NULL;
        }
        if (!find_plr(list, map[i - 1], i - 1))
           return (NULL);
		tmp = tmp->next;
    }
    map[i] = NULL;
	list->max_height = i;
	copy_map(map, i, list);
	return (map);
}

