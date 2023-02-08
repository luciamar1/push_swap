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

void    *doublylink_new(int content, t_doublelist **prevstack, int orden)
{
    t_doublelist *new;
    new = malloc(sizeof(t_doublelist *));
    if (new == NULL)
        return(0);
    new->content = content;
    new->next =  NULL;
    if(orden == 1)
    {
        new->prev = *prevstack;
        *prevstack = new;
        (*prevstack)->prev->next = new;
        return(0);
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
 
void    push_x(t_doublelist **stack_b, t_doublelist **stack_a)
{
    t_doublelist    *swap;

    swap = *stack_a;

    *stack_a = (*stack_a)->next;
    (*stack_a)->prev = NULL;
    printf("PRINTEAMOS LISTA STACK_A \n");
    ft_printlista(*stack_a);

    swap->next = *stack_b;
    printf("PRINTEAMOS LISTA SWAP \n");
    ft_printlista(swap);

    *stack_b = swap;
     printf("PRINTEAMOS LISTA STACK_B \n");
    ft_printlista(*stack_b);

    


    // t_doublelist    *swap;

    // swap = *stack_a;
    // (*stack_a)->next->prev = NULL;
    // *stack_a = (*stack_a)->next;
    // printf("contenido de a == %d\n", swap->content);
    // (*stack_b)->prev = swap;
    // (*stack_b) = (*stack_b)->prev;

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
    // t_doublelist *head_a;
    // t_doublelist *init_a;
    
    // head_a = doublylink_new(atoi(argv[0]), NULL, 0);
    // init_a = head_a;
    // int i = 1;
    // while(i < argc)
    //     doublylink_new(atoi(argv[i++]), &head_a, 1);
    // return( init_a );
}


int main(int argc, char **argv)
{
    t_doublelist *head_a;
    t_doublelist *init_a;
    t_doublelist *init_b;
    t_doublelist *head_b;
  
    if (argc == 1)
        return(0);
    head_b = malloc(sizeof(t_doublelist *));
    head_a = build_lst(++argv, argc - 1);
    init_a = head_a;
    init_b = head_b;
    ft_printlista(init_a);
    printf("\n\n");
    push_x(&init_b, &init_a);
    printf("\n\ninit_b\n");
    ft_printlista(init_b);
    printf("\n\ninit_a\n");
    ft_printlista(init_a);
    return(0);
}


