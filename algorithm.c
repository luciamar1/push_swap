/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/04/28 17:07:57 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int    ft_len_dlist(t_dlist *stack)
{
    int len;
    t_dlist *init;

    if (!stack)
        return (0);
    len = 1;
    init = stack;
    stack = stack->next;
    while(stack != init)
    {
        len ++;
        // printf("len en contar == %d\n", len);
        stack = stack->next;
    }
    return(len);
}

void    put_indice(t_dlist *list)
{
    t_dlist *min;
    int     ind;
    int     len;
    int     l;
   
    len = ft_len_dlist(list);
    min = list;
    ind = 0;
    l = ft_len_dlist(list);
    while(len --)
    {
        l = ft_len_dlist(list);
        while(l-- && (list)->index != -1)
            list = (list)->next;
        min = (list);
        l = ft_len_dlist(list);
        while(l--)
        {
            if((list)->content < min->content && (list)->index == -1)   
                min = list;
            list = (list)->next;
        }
        if(min->index == -1)
            min->index = ind;
        ind ++;
    }
}


void    push_20(t_dlist **stack_a, t_dlist **stack_b)
{
    int len;
    int head;
    int max;
    int optim;
    int op;
    
    len = ft_len_dlist(*stack_a);
    printf("   leeeeen %d\n", len);
    max = len / 5;
    head = 1;
    int cont = 0;
    optim = 0;
    ft_printf_dlist(*stack_a);
    while(*stack_a) 
    {
        while(len --)
        {
            if((*stack_a)->index <= max)
            {
                op = optim;
                while(op --)
                    *stack_a = (*stack_a)->prev;
                while(optim --)
                    rotate(stack_a);
                printf("INDEX %d      MAX %d\n", (*stack_a)->index, max);
                if(head == 1)
                {
                    cont ++;
                    //printf("stack a  == %d     ", (*stack_a)->index);
                    push_x(&(*stack_b), &(*stack_a));
                    head = 0;
                    //printf("GUATATATATTATA push == %d\n", max);
                }
                else 
                {
                    cont++;
                    //printf("stack a  == %d     ", (*stack_a)->index);
                    push_x(&(*stack_b), &(*stack_a));
                    rotate(stack_b);
                    head = 1;
                    //printf("GUATATATATTATA rotate == %d\n", max);
                }
                optim = 0;
            }
            else
            {
                optim ++;
                if (*stack_a)
                    (*stack_a) = (*stack_a)->next;
            }
        }
        if (*stack_a)
            len = ft_len_dlist(*stack_a);
        max += max;
    }
    printf("\n\n\n");
    ft_printf_dlist(*stack_b);
}

int ft_optim(int index, t_dlist *stack_next)
{
    t_dlist *stack_prev;
    int     verif_next;
    int     verif_prev;
    
    stack_prev = stack_next;
    verif_next = 0;
    verif_prev = 0;
    while(stack_next->index != index && stack_prev->index != index)
    {
        stack_next = stack_next->next;
        if (stack_next->index != index )
            verif_next++;
        if (stack_prev->index != index )
            verif_prev++;
    }
    if(verif_prev < verif_next)
        return(0);
    else
        return(1);
}

void    order_nums(t_dlist **stack_b, t_dlist **stack_a)
{
    int len;
    int ind;
    int x;
    int l;
    int saltarin;
    t_dlist *list;

    l = ft_len_dlist(*stack_b);
    ind = l-1;
    list = *stack_b;
    while (l--)
    {
        printf("GUATATATATTATA CONTENT =) %d\n", (list)->index);
        (list) = (list)->next;
    }
     l = ft_len_dlist(*stack_b);
     printf("%d\n",list->index );

    while(l--)
    {
        
        //printf("INDEX == %d        IND === %d\n", list->index, ind);
        len = ft_len_dlist(list);
        saltarin = 0;
        while(list->index != ind)
        {
            list = list->next;
            saltarin ++;
        
            while (l--)
        {
            printf("GUATATATATTATA CONTENT =) %d\n", (list)->index);
            (list) = (list)->next;
        }
                    
            sleep(2);

            printf("I cacacacacacaca NDEX == %d        IND === %d\n", list->index, ind);
        }
        sleep(2);
        printf("caca %p\n", (*stack_a));
       if (list->index == ind && (saltarin / 2) < (len / 2))
       {
           while(saltarin --)
           {
               printf("2\n");
               rotate(stack_b);
           }
       }
       else if (list->index == ind && saltarin / 2 < len / 2)
       {
           while(saltarin --)
           {
               printf("3\n");
               reverse_rotate(stack_b);
           }
       }
       push_x(stack_a, stack_b);
       ind --;
       printf("bucle nucleo %d\n", list->content);
    }
    printf("\n\n\n\nGUATATATATATATA\n");
    //ft_printf_dlist(*stack_a);

}

void    order_num(t_dlist **stack_b, t_dlist **stack_a)
{
    int len;
    int index;
    int arriba;

    index = 0;
    len = ft_len_dlist(*stack_b);
    while(len --)
    {
        arriba = ft_optim(index, *stack_b);
        // printf("buenos dias preciosa =)\n");
        //ft_printf_dlist(*stack_b);
        while((*stack_b)->index != len)
        {
            if(arriba == 1)
            {
                push_x(&(*stack_b), &(*stack_a));
                arriba = 0;
            }
            if(arriba == 0)
            {
                printf("stack a ROTATEEEEE %d\n", (*stack_b)->content);
                push_x(&(*stack_b), &(*stack_a));
                rotate(&(*stack_b));
                arriba = 1;
            }
        }
    }
}

void algorithm(t_dlist **stack_a, t_dlist **stack_b)
{
    
    // while(*stack_a)
    // {
    //      printf("content == %d indice == %d\n", (*stack_a)->content, (*stack_a)->index);
    //     (*stack_a) = (*stack_a)->prev;
    // } 
    //int l = ft_len_dlist(*stack_a);
    int l = ft_len_dlist(*stack_a);
    put_indice(*stack_a);
    push_20(stack_a, stack_b);
    while(l--)
    {
        printf("         content == %d indice == %d\n", (*stack_b)->content, (*stack_b)->index);
        (*stack_b) = (*stack_b)->next;
    }
    order_nums(stack_b, stack_a);
    printf("        len == %d\n", l);
    printf("\n\n\n\n\n");
    // while((*stack_a))
    // {
    //     push_20(stack_a, stack_b, limit);
    //     //ft_printf_dlist(*stack_b);
    //     limit += 20;
    // }
    //ft_printf_dlist(*stack_b);
    // int len = ft_len_dlist(*stack_b);
    // // printf("len == %d\n", len);
    // for(int i = 0; i < 7; i++)
    // {
    //     printf("Len == %d\n", (*stack_b)->content);
    //     *stack_b = (*stack_b)->next;
        
    // }
    exit(1);
    while((*stack_b)->next != (*stack_b)->next->next)
    {
        // printf("while algorithm 1\n");
        order_nums(stack_b, stack_a);
        // printf("%d\n", limit);
    }
    push_x(stack_b, stack_a);
}

