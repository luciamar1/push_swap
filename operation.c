#include <stdio.h>
#include <stdlib.h>

typedef struct s_doublelist {
    int content;
    struct s_doublelist *next;
    struct s_doublelist *prev;
}   t_doublelist;


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

    swap = (*stack_b)->content;
    (*stack_b)->content = (*stack_b)->next->content;
    (*stack_b)->next->content = swap;
}
/* 
int    *push_x(int *stack_x, int *stack_y)
{
    int *stack_ny;
//no se muy bien si en y hay que rota y luego meter el primero del b
//creo que lo mejor es crear otro stack reservar memoria para leng de y 
//+1 meter numero de x y todo y && crear stack x y meter todo x
}


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

t_doublelist *build_lst( char **argv, int argc )
{
    t_doublelist *head_a;
    t_doublelist *init_a;
    
    head_a = doublylink_new(atoi(argv[0]), NULL, 0);
    init_a = head_a;
    int i = 1;
    argc = argc - 2;
    while(argc >= i++)
    {
        printf("holi %d\n", i);
        printf("guatafac\n");
        doublylink_new(atoi(argv[i]), &head_a, 1);
    }
    printf("juju\n");
    return( init_a );
}

void    ft_printlista(t_doublelist *lista)
{
    while(lista->next)
    {
        printf("content %d\n", lista->content);
        lista = lista->next;
    }
    printf("content %d\n", lista->content);
}

int main(int argc, char **argv)
{
    t_doublelist *head_a;
    t_doublelist *init_a;
    t_doublelist *init_b;
    t_doublelist *head_b;
  
    if (argc == 1)
        return(0);
    head_b = build_lst(argv, argc);
    head_a = build_lst(++argv, argc);
    printf("buenop\n");
    init_a = head_a;
    init_b = head_b;
    ft_printlista(init_a);
    printf("hola    \n\n");
    swap_a_and_b(&head_a, &head_b);
    ft_printlista(head_a);
    return(0);
}