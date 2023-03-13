#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_doublelist {
    int content;
    struct s_doublelist *next;
    struct s_doublelist *prev;
}   t_doublelist;

t_doublelist	*ft_lstlast(t_doublelist *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst -> next;
	return (lst);
}

t_doublelist	*ft_lstnew(void *content, t_doublelist **prev)
{
	t_doublelist	*lista;

	lista = (void *)malloc(sizeof(t_doublelist));
	if (lista == NULL)
		return (lista);
	lista->content = content;
	lista->next = NULL;
    lista->prev = *prev;
	return (lista);
}


void	ft_lstadd_back(t_doublelist **lst, t_doublelist *new)
{
	t_doublelist	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new;
    new->prev = last;
}

void	ft_lstadd_front(t_doublelist **lst, t_doublelist *lista)
{
	if (!lista || !lst)
		return ((void) NULL);
	if (lst != NULL)
		lista -> next = *lst;
    (*lst)->prev = lista;
	*lst = lista;
}
