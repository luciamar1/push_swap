/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:13:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/05/05 23:55:16 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_clear_dlist(t_dlist  **list)
{
    if(!*list)
        return(1);
    free(*list);
    while((*list)->next != (*list)->next->next)
    {
        *list = (*list)->next;
        free(*list);
    }
    return(0);
}


void    ft_print_dlist(t_dlist  *list)
{
    t_dlist *head;
    head = list;
    printf("\n\n\n");
    printf("lista == %d\n", list->content);
    list = list->next;
    while(list != head)
    {
        printf("lista == %d\n", list->content);
        list = list->next;
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
    new->index = -1;
    new->prev = *saltarina;
    new->next = NULL;
  
    if (*saltarina != NULL)
    {
        (*saltarina)->next = new;
    }
    *saltarina = new ;
    return(0);
}

char    *create_stack(char *old, char *new)
{
    char    *array;
    char    *space;
    space = ft_strjoin(old, " ");
    array = ft_strjoin(space, new);
    free(old);
    free(space);
    return(array);
}


char **checker(int argc, char **argv)
{
    char    **stack;
    char    *array;
    int     counter;

    if(argc == 1)
        return(NULL);
    counter = 2;
    array = ft_strdup(argv[1]);
    while(argv[counter])
    {
        array = create_stack(array, argv[counter++]);
    }
    stack = ft_split(array, ' ');
    free(array);
    return(stack);
}

int main(int argc, char **argv)
{
    t_dlist *stack_a;
    t_dlist *stack_b;
    char    **stack;
    int     i;
    int     ai;
    int     error;

    error = 0;
    stack = checker(argc, argv);
    if (stack == NULL)
        return(1);
    stack_b = NULL;
    t_dlist *f_stack_a;
    i = 0;
    f_stack_a = NULL;
    ai = ft_atoi_chetao(stack[i++], &error);
    if(error == 1)
        return(1);
    ft_create_dlist(&f_stack_a, ai);
    stack_a = f_stack_a;
    while(stack[i])
    {
        ai = ft_atoi_chetao(stack[i++], &error);
        if(error == 1)
            return(1);
       
        ft_create_dlist(&f_stack_a, ai);
    }
    f_stack_a->next = stack_a;
    stack_a->prev = f_stack_a;
    ft_freecharmatrix(stack);
    
    algorithm(&stack_a, &stack_b);
    //ft_print_dlist(stack_a);
    //ft_printf_dlist_ind(stack_a);
    return (0);
}