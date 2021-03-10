#include "../include/cub3d.h"

static void find_line_max_size(t_info *list, char *line)
{
    int size;

    size = ft_strlen(line);
    if (list->max_size < size)
        list->max_size = size;
}

int 	get_map(t_info *list, char *line, t_list **head)
{
    int i;

    i = 0;
	//if (!is_map(line))
	//	return (0); //Обработать ошибку
    list->map_exist = 1;
    find_line_max_size(list, line);
    ft_lstadd_back(head, ft_lstnew(line));
    return (1);
}
