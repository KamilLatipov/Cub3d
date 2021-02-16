#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

    tmp = *alst;
    if (alst && *alst)
    {
        while (tmp->next)
        {
           tmp = tmp->next;
        }
        tmp->next = new;
    }
    else if (alst)
        *alst = new;
    //printf("head = %s\n", tmp->next->content);
}

