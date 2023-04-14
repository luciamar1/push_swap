/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/04/14 18:30:29 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_len_dlist(t_dlist *stack)
{
    int len;
    t_dlist *init;

    len = 1;
    init = stack;
    stack = stack->next;
    while(stack->content != init->content)
    {
        len ++;
        stack = stack->next;
    }
    return(len);
}

void    push_20(t_dlist **stack_a, t_dlist **stack_b, int max)
{
    int len;
    
    len = ft_len_dlist(*stack_a);
    // printf("===== %d\n", len);
    while(len --)
    {
        //printf("max %d     content %d\n", max, (*stack_a)->content);
        if((*stack_a)->content <= max)
        {
            // printf("HA ENCONTRADO LIMITE %d\n", (*stack_a)->content);
            push_x(&(*stack_b), &(*stack_a));
            // printf("GUATATATAAAAAA %d\n", (*stack_a)->content);
            // printf("GUATATATAAAAAA NEXT %d\n", (*stack_a)->next->next->content);
            // printf("GUATATATAAAAAA PREV %d\n", (*stack_a)->prev->content);
        }
        else
            *stack_a = (*stack_a)->next;
       //printf("while push %d\n", (*stack_a)->content);
    }
    printf("stack_a == %d\n", (*stack_a)->content);
}

void    order_nums(t_dlist **stack_b, t_dlist **stack_a)
{
    int     limit;
    t_dlist *max;

    max = *stack_b;
    limit = 20;
    while(limit && (*stack_b)->next != (*stack_b)->next->next)
    {
        // printf("while order_nums\n");
        if((*stack_b)->content > max->content)
            max = *stack_b;
        (*stack_b) = (*stack_b)->next;
        limit --;
    }
    if((*stack_b)->next != (*stack_b)->next->next)
        push_x(&max, stack_a);
}

void algorithm(t_dlist **stack_a, t_dlist **stack_b)
{
    int limit;

    limit = 20;
    while((*stack_a))
    {
        // printf("CARAPAAAAAAAAAN    limit ====  %d\n", limit);
        push_20(stack_a, stack_b, limit);
        limit += 20;
    }
    while((*stack_b)->next != (*stack_b)->next->next)
    {
        // printf("while algorithm 1\n");
        order_nums(stack_b, stack_a);
    }
    push_x(stack_b, stack_a);
}

