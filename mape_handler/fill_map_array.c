#include "../include/cub3d.h"

void fill_map_array(t_list **head, int size)
{
	char	  **map;
	int		  i;

	map = malloc(size + 1, sizeof(char *));
	ft_bzero(map, sizeof(size + 1));
	i = -1;
	t_list	*tmp = *head;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp= tmp->next;
	}
	i = -1;
	return (map);
}

