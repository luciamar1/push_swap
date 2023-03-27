/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:13:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/03/27 17:45:05 by lucia-ma         ###   ########.fr       */
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
    return(0);
}

int swap_a_or_b(t_dlist  **stack)
{
    
    int     swap;
    
    if(!*stack)
        return (1);
    swap = (*stack)->content;
    (*stack)->content = ((*stack)->prev->content);
    (*stack)->prev->content = swap;
    return(0);
}

void    swap_a_and_b(t_dlist **stack_a, t_dlist **stack_b)
{
    swap_a_or_b(stack_a);
    swap_a_or_b(stack_b);
}

void    push_x(t_dlist **stack_b, t_dlist **stack_a)
{
        t_dlist    *swap;

        swap = *stack_a;
        *stack_a = (*stack_a)->next;
        (*stack_a)->prev = NULL;

        swap->next = *stack_b;
        *stack_b = swap;
}



int main(int argc, char **argv)
{
    t_dlist *stack_a;
    t_dlist *stack_b;
    int     i;
    int ar = argc;
    t_dlist *f_stack_a;
    i = ar;
    i = 1;
    stack_a = NULL;
    ft_create_dlist(&stack_a, ft_atoi(argv[i++]));
    f_stack_a = stack_a;

    while(argv[i])
    {
        ft_create_dlist(&stack_a, ft_atoi(argv[i++]));
    }
    
    //swap_a_or_b(&f_stack_a);
    //swap_a_and_b(&f_stack_a, &stack_b);

    printf("%d\n", f_stack_a->content);
    printf("%d\n", f_stack_a->prev->content);
    printf("%d\n", f_stack_a->prev->prev->content);    
    //ft_print_dlist(stack_a);
    return (0);
}