/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/03/28 20:59:20 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    algorithm_stack_a(t_dlist **stack_a, t_dlist **stack_b)
{
    int pivot;
    
    pivot = (*stack_a)->prev->content;
    while((*stack_a)->content != pivot)
    {
        if((*stack_a)->content < pivot)
        {
            push_x(stack_b, stack_a);
        }
        *stack_a = (*stack_a)->next;
    }
}

void    algorithm_stack_b(t_dlist **stack_a, t_dlist **stack_b)
{
    
}