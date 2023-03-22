/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:13:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/03/22 19:46:31 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_print_dlist(t_dlist  *list)
{
    printf("primero %d\n", list->content);
    
    while(list->next)
    {
        printf("\n\n\n");
        printf("prev %d\n", list->content);
        printf("content %d\n", list->next->content);
        printf("next %d\n", list->prev->content);
        list = list->next;
        printf("\n\n\n");
    }
}

void    *ft_create_dlist(t_dlist **saltarina, int data)
{
    t_dlist *new;
    
    new = malloc(sizeof(t_dlist *));
    if(!new)
    {
        ft_lstclear(saltarina, 1);
        return (1);
    }
    new->content = data;
    new->next = *saltarina;
    
    if (*saltarina != NULL)
        (*saltarina)->prev = new;
    *saltarina = (*saltarina)->prev;
}

int main(int argc, char **argv)
{
    t_dlist *stack_a;
    int     i;

    i = 1;
    stack_a = NULL;
    while(argc --)
        ft_create_dlist(&stack_a, ft_atoi(argv[i++]));
    ft_print_dlist(stack_a);
    return (0);
}