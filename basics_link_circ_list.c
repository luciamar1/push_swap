/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics_link_circ_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:12:19 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/05/15 19:12:36 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_clear_dlist(t_dlist  **list)
{
    if(!*list)
        return(1);
    free(*list);
    while((*list)->next != (*list)->next->next)
    {
        *list = (*list)->next;
        free(*list);
    }
    return(0);
}


void    ft_print_dlist(t_dlist  *list)
{
    t_dlist *head;
    head = list;
    printf("\n\n\n");
    printf("lista == %d\n", list->content);
    list = list->next;
    while(list != head)
    {
        printf("lista == %d\n", list->content);
        list = list->next;
    }
}