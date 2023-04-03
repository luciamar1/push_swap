/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/04/03 12:30:08 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_20(t_dlist **stack_a, t_dlist **stack_b, int max)
{
    if((*stack_a)->content < max)
            push_x(stack_a, stack_b);
    while((*stack_a)->next != (*stack_a)->next->next)
    {
        *stack_a = (*stack_a)->next;
        if((*stack_a)->content < max)
            push_x(stack_a, stack_b);
    }
}

void    order_nums(t_dlist **stack_b, t_dlist **stack_a)
{
    int     limit;
    t_dlist *max;

    max = *stack_b;
    limit = 20;
    while(limit && (*stack_b)->next != (*stack_b)->next->next)
    {
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
    while((*stack_a)->next != (*stack_a)->next->next)
    {
        push_20(stack_a, stack_b, limit);
        limit += 20;
    }
    while((*stack_b)->next != (*stack_b)->next->next)
    {
        order_nums(stack_b, stack_a);
    }
    push_x(stack_b, stack_a);
}
