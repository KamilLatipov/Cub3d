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

char **fill_map_array(t_list **head, int size, t_info *list)
{
	char	  **map;
	int		  i;

	map = malloc((size + 1) * sizeof(char *));
	ft_bzero(map, sizeof(size + 1));
	i = 0;
	t_list	*tmp = *head;
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
	return (map);
}

