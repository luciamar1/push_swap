#include <stdio.h>
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

void    ft_freedoublelist(t_doublelist *lista)
{
    lista = lista->next;
    while(lista->next)
    {
        free(lista->prev);
        lista = lista->next;
    }
}

void    *doublylink_new(int content, t_doublelist *prevstack, int orden)
{
    t_doublelist *new;
    new = malloc(sizeof(t_doublelist *));
    if (new == NULL)
        return(NULL);
    new->content = content;
    new->next =  NULL;
    printf("plis%d\n", new->content);
    if(orden == 1)
    {
        new->prev = prevstack;
        prevstack = new;
        prevstack->prev->next = new;
        printf("        2       plis%d\n", new->content);
        return("bien");
    }
    new->prev = NULL;
    return(new);
}

void    swap_a_or_b(t_doublelist  **stack)
{
    int swap;
    swap = (*stack)->content;
    (*stack)->content = ((*stack)->next->content);
    (*stack)->next->content = swap;
}

void    swap_a_and_b(t_doublelist **stack_a, t_doublelist **stack_b)
{
    int swap;

    swap = (*stack_a)->content;
    (* stack_a)->content = (*stack_a)->next->content;
    (*stack_a)->next->content = swap;

    if((*stack_b)->content)
    {
        swap = (*stack_b)->content;
        (*stack_b)->content = (*stack_b)->next->content;
        printf("donde fallas bebe?\n"); 
        (*stack_b)->next->content = swap;
    }
}
 
void    push_x(t_doublelist *stack_b, t_doublelist *stack_a)
{
    t_doublelist    *swap;

    swap = stack_a;
    stack_a = (stack_a)->next;
    (stack_a)->prev = NULL;
    swap->next = stack_b;
    stack_b = swap;
    printf("PRINTEAMOS LISTA SWAP \n");
    ft_printlista(swap);
    printf("PRINTEAMOS LISTA STACK_A \n");
    ft_printlista(stack_a);
    printf("PRINTEAMOS LISTA STACK_B \n");
    ft_printlista(stack_b);
}

/*
void rotate_a_or_b(int *stack)
{
    int init;
    int contador;

    init = stack[1];
    contador = 1;
    stack[0] == init;
    while(stack[counter] != init)
    {
        stack
    }
}*/



t_doublelist *build_lst( char **argv, int argc)
{
    t_doublelist    *head_a;
    t_doublelist    *init_a;
    
    head_a = doublylink_new(atoi(argv[0]), NULL, 0);
    if(head_a == NULL)
        return (NULL);
    init_a = head_a;
    printf("INIT_A =)\n");
    ft_printlista(init_a);
    printf("INIT_A =)\n\n");
    int i = 1;
    while(i < argc)
    {
        if (doublylink_new(atoi(argv[i++]), head_a, 1) == NULL)
        {
            printf("sdsojjdjojds\n");
            ft_freedoublelist(head_a);
            return(NULL);
        }
    }
    printf("INIT_A =)\n");
    ft_printlista(init_a);
    printf("INIT_A =)\n\n");
    return( init_a );
}


int main(int argc, char **argv)
{
    t_doublelist *head_a;
    t_doublelist *init_a;
    t_doublelist *init_b;
    t_doublelist *head_b;
  
    if (argc == 1)
        return(1);
    // head_b = malloc(sizeof(t_doublelist *));
    // if(head_b == NULL)
    //     return (0);
    head_a = build_lst(++argv, argc - 1);
    if (head_a == NULL)
        return (1);
    init_a = head_a;
    init_b = head_b;
    printf("init_a\n");
    ft_printlista(init_a);
    printf("\n\n");
    push_x(init_b, init_a);
    return(0);
}


