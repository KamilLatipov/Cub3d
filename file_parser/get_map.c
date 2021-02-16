#include "../include/cub3d.h"

int 	get_map(t_info *list, char *line, t_list **head)
{
	if (!is_map(line))
		return (0); //Обработать ошибку
    list->map_exist = 1;
    //if (head)
      // printf("head content before = %s\n", *head->content);
    ft_lstadd_back(head, ft_lstnew(line));
   // printf("head content = %s\n", *head->content);
    return (1);
}
