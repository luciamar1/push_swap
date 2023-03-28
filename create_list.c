/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:13:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/03/28 18:49:26 by lucia-ma         ###   ########.fr       */
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
    new->prev = *saltarina;
    new->next = NULL;
  
    if (*saltarina != NULL)
    {
        (*saltarina)->next = new;
    }
    //printf("array %d\n", (*saltarina)->content);
    *saltarina = new ;
    return(0);
}

int main(int argc, char **argv)
{
    t_dlist *stack_a;
    //t_dlist *stack_b;
    int     i;
    int ar = argc;
    //t_dlist *f_stack_b;
    t_dlist *f_stack_a;
    i = ar;
    i = 1;
    f_stack_a = NULL;
    ft_create_dlist(&f_stack_a, ft_atoi(argv[i++]));
    stack_a = f_stack_a;

    while(argv[i])
    {
        ft_create_dlist(&f_stack_a, ft_atoi(argv[i++]));
    }
    f_stack_a->next = stack_a;
    stack_a->prev = f_stack_a;
    //swap_a_or_b(&f_stack_a);
    //swap_a_and_b(&f_stack_a, &stack_b);
    reverse_rotate(&stack_a);
    printf("%d\n", stack_a->content);
    printf("%d\n", stack_a->next->content);
    printf("%d\n", stack_a->next->next->content);
    //ft_print_dlist(stack_a);
    return (0);
}