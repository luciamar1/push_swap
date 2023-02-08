#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_doublelist {
    int content;
    struct s_doublelist *next;
    struct s_doublelist *prev;
}   t_doublelist;

void    ft_printlista(t_doublelist *lista)
{
    while(lista->next)
    {
        printf("content %d\n", lista->content);
        lista = lista->next;
    }
    printf("content %d\n", lista->content);
}

void build_list(t_doublelist **stack, char **argv, int argc)
{
    t_doublelist    *swap;
    t_doublelist    *init;
    int             i;

    i = 0;
    init = *stack;
    while(i < argc)
    {
        swap->prev = *stack;
        swap->next = NULL;
        swap->content = atoi(argv[i]);
        i++;
        (*stack)->next= swap;
        *stack = (*stack)->next;
    }   
    ft_printlista(init);
    *stack = init;
}

int main(int argc, char **argv)
{
    t_doublelist    *stack;

    stack =  malloc(sizeof(t_doublelist *));
    build_list(&stack, argv, argc);
    ft_printlista(stack);
}