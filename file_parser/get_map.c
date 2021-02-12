#include "../include/cub3d.h"

void 	get_map(t_info *list, char *line, char *map)
{
	if (!is_map(line))
		return (NULL); //Обработать ошибку;
	ft_lstadd_back(&list->head, ft_lstnew(line));
}

