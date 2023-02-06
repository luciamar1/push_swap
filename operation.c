#include <stdio.h>
#include <stdlib.h>

struct node {
    int content;
    struct node *next;
    struct node *prev;
};

void    *doublylink_new(int content, struct node **prevstack, struct node *head, int orden)
{
    struct node *new;
    new = malloc(sizeof(struct node));
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

void    swap_a_or_b(struct node  **stack)
{
    int swap;
    swap = (*stack)->content;
    (*stack)->content = ((*stack)->next->content);
    printf("que esta mal?\n");
    (*stack)->next->content = swap;
}
/*
void    swap_a_and_b(int  *stack_a, int *stack_b)
{
    int swap;

    swap = stack_a[0];
    stack_a[0] = stack_a[1];
    stack_a[1] = swap;
    int swap;
    swap = stack_b[0];
    stack_b[0] = stack_b[1];
    stack_b[1] = swap;
}

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

struct node *build_lst( char **argv, int argc )
{
    struct node *head_a;
    struct node init_a;

    head_a = doublylink_new(atoi(argv[1]), NULL, NULL, 0);
    init_a = head_a;
    printf("head_a == %d\n", head_a->content);
    int i = 1;
    while( ++i < argc)
    {
        doublylink_new(atoi(argv[i]), &head_a, head_a->head, 1);
        printf("head_a == %d\n", head_a->content);
    }
    return( init_a );
}

int main(int argc, char **argv)
{
    struct node *head_a;
  
    if (argc == 1)
        return(0);

    head_a = build_lst(argv, argc);
    printf("%d\n", head_a->content);
    head_a = head_a->head;
    swap_a_or_b(&head_a);
    return(0);
}