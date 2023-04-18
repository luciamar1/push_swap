/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:27:02 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/04/17 11:37:28 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_dlist **stack_a)
{
    *stack_a = (*stack_a)->prev;
}

void reverse_rotate_a_b(t_dlist **stack_a, t_dlist **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}

void rotate(t_dlist **stack_a)
{
    *stack_a = (*stack_a)->next;
}

void rotate_a_and_b(t_dlist **stack_a, t_dlist **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
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

// void    push_x(t_dlist **stack_b, t_dlist **stack_a)
// {
//     t_dlist    *swap;

//     swap = *stack_a;
//     *stack_a = (*stack_a)->next;
//     (*stack_a)->prev = swap->prev;
//     swap->next = *stack_b;
//     if(stack_b)
//     {
//         swap->prev = (*stack_b)->prev;
//         (*stack_b)->prev = swap;
//     }
//     printf("guatatatatattatatatatatatatatatatatata     =====    \n");
//     *stack_b = swap;
//     (*stack_b)->next = *stack_b;
//     if(*stack_a == swap)
//         *stack_a = NULL;
// }

void    ft_printf_dlist(t_dlist *list)
{
    t_dlist *start;
    
    start = list;
    printf("print list == %d\n", list->content);
    list = list->next;
    while(list->content != start->content)
    {
        printf("print list == %d\n", list->content);
        list = list->next;
    }
    printf("\n\n");
}

void    push_x(t_dlist **stack_b, t_dlist **stack_a)
{
    t_dlist   *swap;

    swap = *stack_a;
    if(ft_len_dlist(*stack_a) == 1)
        *stack_a = NULL;
    else
    {
        *stack_a =  (*stack_a)->next;
        (*stack_a)->prev = swap->prev;
        (*stack_a)->prev->next = *stack_a;
    }
    //printf("%d\n", (*stack_a)->prev->next->content);
    if(*stack_b)
    {
        swap->prev = (*stack_b)->prev;
        swap->next = (*stack_b)->next;
        (*stack_b)->prev->next = swap;
        (*stack_b)->prev = swap;
        *stack_b = swap;
    }
    else
    {
        *stack_b = swap;
        (*stack_b)->next = (*stack_b);
        (*stack_b)->prev = (*stack_b);
    }
}

void    swap_a_and_b(t_dlist **stack_a, t_dlist **stack_b)
{
    swap_a_or_b(stack_a);
    swap_a_or_b(stack_b);
}