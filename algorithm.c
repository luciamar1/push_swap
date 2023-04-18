/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/04/18 19:46:47 by lucia-ma         ###   ########.fr       */
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

void    put_indice(t_dlist **list)
{
    t_dlist *head;
    t_dlist **min;
    int     ind;
    int     len;
    
    len = ft_len_dlist(*list);
    head = *list;
    min = &(*list);
    ind = 0;
    while(len --)
    {
         *list = (*list)->next;
        while((*list)->content != head->content)
        {
            if((*list)->content < (*min)->content)
                min = &(*list);
            *list = (*list)->next;
        }
        if((*list)->content < (*min)->content)
            (*min)->index = ind;
        ind ++;
    }
}


void    push_20(t_dlist **stack_a, t_dlist **stack_b, int max)
{
    int len;
    int head;
    
    head = 1;    
    len = ft_len_dlist(*stack_a);
    // printf("===== %d\n", len);
    while(len --)
    {
        if((*stack_a)->content <= max)
        {
            if(head == 1)
            {
                push_x(&(*stack_b), &(*stack_a));
                head = 0;
            }
            if(head == 0)
            {
                push_x(&(*stack_b), &(*stack_a));
                rotate(stack_b);
                head = 1;
            }
            //ft_printf_dlist(*stack_a);
        }
        else
            *stack_a = (*stack_a)->next;
    }
}

void    order_nums(t_dlist **stack_b, t_dlist **stack_a)
{
    
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

