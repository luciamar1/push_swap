/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/05/04 17:18:05 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    put_baby_ind(t_dlist *a, int len)
{    
    if(len == 3)
    {
        while(len --)
        {
            a->index --;
            a = a->next;
        }
    }
    if (len == 4 || len == 5)
    {
        len --;
        a = a->next;
        if(len == 4)
        {
            len --;
            a = a->next;
        }
        while(len )
        {
            a->index ++;
            a = a->next;
            len --;
        }
    }
    
}

void    three_alg(t_dlist **a)
{
    // while(!((*a)->index < (*a)->next->index && (*a)->next->index < (*a)->next->next->index))
    // {
    //     if ((*a)->index < (*a)->next->index)
    //         reverse_rotate(a, 'a');
    //     if ((*a)->index > (*a)->next->index && (*a)->next->index < (*a)->next->next->index)
    //         rotate(a, 'a');
    //     else if (!((*a)->index < (*a)->next->index && (*a)->next->index < (*a)->next->next->index))
    //         swap_a_or_b(a, 'a');
    // }
    printf("                 GUAAAAAAAAAAAAAA \n");
    if ((*a)->index == 0 && (*a)->next->index == 2)
        swap_a_or_b(a, 'a');
    if ((*a)->index == 2 && ((*a)->next->index == 1 || (*a)->next->index == 0))
        rotate(a, 'a');
    if ((*a)->index == 1 && (*a)->next->index == 0)
        swap_a_or_b(a, 'a');
    if ((*a)->index == 1 && (*a)->next->index == 2)
        reverse_rotate(a, 'a');
}

void    four_alg(t_dlist **a, t_dlist **b)
{
    int count;
    t_dlist *utils;

    utils = *a;
    count = 0;
    while(utils->index != 0)
    {
        utils = utils->next;
        count ++;
    }
    if(count / 2 < 2)
        while (count --)
            rotate(a, 'a');
    else
        while (count --)
            reverse_rotate(a, 'a');
    push_x(b, a, 'b');
    put_baby_ind(*a, 3);
                    printf("GUAAAAAAAAAAAA           INDICE =) \n");
                    ft_printf_dlist_ind(*a);
    three_alg(a);
                    printf("                   HOLAAAAAAAAAAAAAA  three algorithm\n");
                    ft_printf_dlist_ind(*a);
    push_x(a, b, 'a');
    put_baby_ind(*a, 4);
}

void    five_alg(t_dlist **a, t_dlist **b)
{
    int count;
    int min;
    int i;
    t_dlist *util;

    i = 2;
    min = 0;
    count = 0; 
    util = *a;

    while(i --)
    {
        count = 0;
        ft_printf_dlist_ind(util);
        while(util->index != min)
        {
            printf("       FIVE  0                 %d\n", util->index);
            util = util->next; 
            count ++;
        }
        sleep(2);
        printf("GUATATTATATA\n");
        if(count / 2 < 2)
        {
            while (count --)
            {
                printf("       FIVE 1\n");
                rotate(a, 'a');
            }

        }
        else
        {
            
            while (count --)
                reverse_rotate(a, 'a');
        }
        push_x(b, a, 'b');
        min ++;
    }

    put_baby_ind(*a, 3);
    three_alg(a);
    push_x(a, b, 'a');
    push_x(a, b, 'a');
    put_baby_ind(*a, 5);
}

void    select_algorithm(t_dlist **stack_a, t_dlist **stack_b)
{
    int len;

    len = ft_len_dlist(*stack_a);
    if(len == 2 &&  (*stack_a)->content > (*stack_a)->next->content )
        rotate(stack_a, 'a');
    if(len == 3)
        three_alg(stack_a);
    if(len == 4)
        four_alg(stack_a, stack_b);
    if(len == 5)
        five_alg(stack_a, stack_b);
}