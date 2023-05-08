/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:27:02 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/05/05 20:50:13 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_dlist **stack_a, char stack)
{
    if(!*stack_a)
        return;
    *stack_a = (*stack_a)->prev;
    if(stack == 'a')
        write(1, "rra\n", 4);
    if(stack == 'b')
        write(1, "rrb\n", 4);
}

void reverse_rotate_a_b(t_dlist **stack_a, t_dlist **stack_b, char stack)
{
    reverse_rotate(stack_a, stack);
    reverse_rotate(stack_b, stack);
}

void rotate(t_dlist **stack_a, char stack)
{
    if(*stack_a)
        *stack_a = (*stack_a)->next;
    if(stack == 'a')
        write(1, "ra\n", 3);
    if(stack == 'b')
        write(1, "rb\n", 3);
    
}

void rotate_a_and_b(t_dlist **stack_a, t_dlist **stack_b, char stack)
{
    rotate(stack_a, stack);
    rotate(stack_b, stack);
}

int swap_a_or_b(t_dlist  **stack, char letter)
{
    
    int     swap;
    
    if(!*stack)
        return (1);
    swap = (*stack)->content;
    (*stack)->content = ((*stack)->next->content);
    (*stack)->next->content = swap;
    swap = (*stack)->index;
    (*stack)->index = ((*stack)->next->index);
    (*stack)->next->index = swap;
    if(letter == 'a')
        write(1, "sa\n", 3);
    if(letter == 'b')
        write(1, "sb\n", 3);
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
    list = list->next;
    while(list->content != start->content)
    {
        list = list->next;
    }
    printf("\n\n");
}

/*void    push_x(t_dlist **stack_b, t_dlist **stack_a)
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
    if((*stack_b)->content)
    {
        printf("yes stack_b\n");
        swap->prev = (*stack_b)->prev;
        swap->next = (*stack_b);
        (*stack_b)->prev->next = swap;
        (*stack_b)->prev = swap;
        *stack_b = swap;
    }
    else
    {
        printf("no\n");
        ft_printf_dlist(*stack_a);
        write(1,"hol\na\n", 5);
        //printf("GUATATATATA\n");    
        printf("no stack_b\n");
        *stack_b = swap;
        (*stack_b)->next = (*stack_b);
        (*stack_b)->prev = (*stack_b);
    }
    printf("GUATATATATA\n");

}*/

void    push_x(t_dlist **stack_b, t_dlist **stack_a, char stack)
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
    if(*stack_b)
    {
        swap->prev = (*stack_b)->prev;
        swap->next = (*stack_b);
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
    if(stack == 'a')
        write(1, "pa\n", 3);
    if(stack == 'b')
        write(1, "pb\n", 3);
}

void    swap_a_and_b(t_dlist **stack_a, t_dlist **stack_b)
{
    swap_a_or_b(stack_a, 'a');
    swap_a_or_b(stack_b, 'b');
}