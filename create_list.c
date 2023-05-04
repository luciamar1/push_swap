/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:13:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/04/20 20:48:22 by lucia-ma         ###   ########.fr       */
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

char *create_stack(char *old, char *new)
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
    printf("SPLIT   ==  %s\n", array);
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
    int ar = argc;

    stack = checker(argc, argv);
    if (stack == NULL)
        return(1);
    int x = 0;
    while(stack[x])
        printf("array == %s", stack[x++]);
    stack_b = NULL;
    t_dlist *f_stack_a;
    i = ar;
    i = 0;
    f_stack_a = NULL;
    ft_create_dlist(&f_stack_a, ft_atoi(stack[i++]));
    stack_a = f_stack_a;
    while(stack[i])
    {
        ft_create_dlist(&f_stack_a, ft_atoi(stack[i++]));
    }
    f_stack_a->next = stack_a;
    stack_a->prev = f_stack_a;
    printf("\nHOOOOOLIIIIIIIIIS\n\n");
    ft_print_dlist(stack_a);
    printf("\nHOOOOOLIIIIIIIIIS\n\n");
    
    algorithm(&stack_a, &stack_b);
    ft_print_dlist(stack_a);
    ft_printf_dlist_ind(stack_a);
    return (0);
}