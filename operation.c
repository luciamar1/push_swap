#include <stdio.h>
#include <stdlib.h>

struct node {
    int content;
    struct node *next;
    struct node *prev;
};

void    doublylink_new(char content, struct node *nextstack, struct node *prevstack)
{
    struct node *new;

    new = (struct node*) malloc(sizeof(struct node));
    new->content = content;
    new->next =  nextstack;
    new->prev = prevstack;
}
/*
void    swap_a_or_b(struct node  *stack)
{
    int swap;

    swap = stack[0];
    stack[0] = stack[1];
    stack[1] = swap;
}

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

void ft_printlist(struct node *head) 
{
    printf("kaka\n");
    struct node *temp = head;
    while (temp != NULL) {
        printf("vuvuvu %c\n", temp->content);
        temp = temp->next;
    }
}

int main(int argc, char **argv)
{
    struct node *head_a;
    int contador;

    contador = 0;
    head_a = (struct node *) malloc(sizeof(struct node));
    if (argc == 1)
        return(0);
    argv ++;
    while(argv[contador][0])
    {
        printf("kaka %c\n", **argv);
        doublylink_new(**argv, head_a, NULL);
        printf("jijijiult %c\n", **argv);
        contador ++;
        printf("ult %c\n", **argv);
    }
    ft_printlist(head_a);
    return(0);
}