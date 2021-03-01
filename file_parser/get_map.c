#include "../include/cub3d.h"

int 	get_map(t_info *list, char *line, t_list **head)
{
	if (!is_map(line))
		return (0); //Обработать ошибку
    list->map_exist = 1;
    ft_lstadd_back(head, ft_lstnew(line));
    return (1);
}
