#include "libft.h"

t_list  *ft_lstlast(t_list *list)
{
    if (list == NULL)
        return (0);
    while (list)
    {
        if (list->next == NULL)
            return (list);
        list = list->next;
    }
    return (list);
}