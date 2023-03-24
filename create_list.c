/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:13:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/03/24 20:24:12 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_clear_dlist(t_dlist  **list)
{
    while((*list)->next)
    {
        *list = (*list)->next;
        free((*list)->prev);
    }
    free(*list);
}


void    ft_print_dlist(t_dlist  *list)
{
    printf("primero %d\n", list->content);
    //list = list->next;
    while(list->next)
    {
        printf("\n\n\n");
        //printf("prev %d\n", list->content);
        printf("content %d\n", list->next->content);
        printf("next %d\n", list->prev->content);
        list = list->next;
        printf("\n\n\n");
    }
}

int ft_create_dlist(t_dlist **saltarina, int data)
{
    t_dlist *new;
    
    new = malloc(sizeof(t_dlist));
    if(!new)
    {
        ft_clear_dlist(saltarina);
        return (1);
    }
    new->content = data;
    new->next = *saltarina;
    new->prev = NULL;
  
    if (*saltarina != NULL)
    {
        (*saltarina)->prev = new;
    }
    //printf("array %d\n", (*saltarina)->content);
    *saltarina = new ;
    printf("ooooyyyyyyeeee %d\n", (*saltarina)->content);
    return(0);
}

char *ft_reverse_string(char *str)
{
    int swap;
    int len;
    int i;
    int impar;
    
    len = ft_strlen(str);
    if(len % 2 != 0)
    {
        swap = len / 2;
        impar = 1;
    }
    else 
        impar = 0;
    i = 0;
    while(len)
    {
        if(impar == 1 && len-- == swap)
            str[i] = str[swap];        
        else
            str[i++] = str[len--];
    }
    return(str);
}

int main(int argc, char **argv)
{
    t_dlist *stack_a;
    int     i;
    int ar = argc;
    i = ar;
    i = 1;
    stack_a = NULL;
    
    while(argv[i])
    {
        argv[i] = ft_reverse_string(argv[i]);
        printf("string reverse%s\n", argv[i]);
        ft_create_dlist(&stack_a, ft_atoi(argv[i++]));
    }
    printf("%d\n", stack_a->content);
    printf("%d\n", stack_a->next->content);
    printf("%d\n", stack_a->next->next->content);    
    //ft_print_dlist(stack_a);
    return (0);
}