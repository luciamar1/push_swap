#include <stdio.h>
#include <stdlib.h>

typedef struct s_doublelist {
	int					content;
	struct s_doublelist	*next;
	struct s_doublelist	*prev;
}	t_dlist;

void    ft_print_dlist(t_dlist  *list)
{
    printf("primero %d\n", list->content);
    
    while(list->next)
    {
        printf("\n\n\n");
        //printf("prev %d\n", list->content);
        printf("content %d\n", list->next->content);
        printf("next %d\n", list->prev->content);
        list = list->next;
        printf("\n\n\n");
    }
}

void    ft_clear_dlist(t_dlist  **list)
{
    while((*list)->next)
    {
        *list = (*list)->next;
        free((*list)->prev);
    }
    free(*list);
}


int    ft_create_dlist(t_dlist **saltarina, int data)
{
    t_dlist    *new;
    printf("jsdsjdgjsdjsgd %d\n", (*saltarina)->content);
     
    new = malloc(sizeof(t_dlist *));
    if(!new)
    {
        ft_clear_dlist(saltarina);
        return (1);        
    }
    new->content = data;
    new->next = *saltarina;
    new->prev = NULL;
    if(*saltarina != NULL)
        (*saltarina)->prev = new;
    *saltarina = new;
    return (0);
}

int main(int argc, char **argv)
{
    t_dlist    *lista_a;
    int             i;

    i = 1;
    lista_a = NULL;
    while(argv[i])
        ft_create_dlist(&lista_a, ft_atoi(argv[i++]));
    ft_print_dlist(lista_a);
    return(0);
}
