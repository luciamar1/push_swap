#include <stdio.h>
#include <stdlib.h>

typedef struct s_doublelist {
	int					content;
	struct s_doublelist	*next;
	struct s_doublelist	*prev;
}	t_doublelist;


void	ft_printlista_prev(t_doublelist *lista, int counter)
{
	while(counter --)
	{
		lista = lista->next;
		printf("CONTENT == %d\n", lista->prev->content);
	}
}

void	ft_printlista(t_doublelist *lista, char x)
{
	printf("\n\n");
	while (lista->next)
	{
		printf("printlista %c contenido == %d\n", x, lista->content);
		lista = lista->next;
	}
	printf("printlista %c contenido == %d\n", x, lista->content);

}
t_doublelist	*guat(char **argv)
{
	t_doublelist	*start;
	t_doublelist	*saltarina;
	t_doublelist	*ayudante;
	t_doublelist	*aux;
	int i;

	i = 1;
	saltarina = malloc(sizeof(t_doublelist *));
	start = saltarina;
	saltarina->content = atoi(argv[i++]);
	saltarina->next = NULL;
	saltarina->prev = NULL;
	while (argv[i])
	{
		//aux = saltarina;
		ayudante = malloc(sizeof(t_doublelist *));
		ayudante->content = atoi(argv[i]);
		ayudante->next = NULL;
		ayudante->prev = NULL;
		//ayudante->prev = saltarina;
		saltarina->next = ayudante;
		saltarina = ayudante;
		//saltarina->prev = aux;
		i ++;
		//ft_printlista(saltarina, 'e');
	}
	saltarina = start;
	while (saltarina->next)
	{
		aux = saltarina;
		saltarina = saltarina->next;
		saltarina->prev = aux;
	}
	
		printf("                                    venga prev == %d\n", saltarina->prev->prev->content);
	// ft_printlista(start, 'a');
	return(start);
}

t_doublelist	*guatafacgege(char **argv)
{
	t_doublelist	*start;
	t_doublelist	*saltarina;
	t_doublelist	*ayudante;
	t_doublelist	*aux;
	int i;

	i = 1;
	saltarina = malloc(sizeof(t_doublelist *));
	start = saltarina;
	saltarina->content = atoi(argv[i++]);
	saltarina->next = NULL;
	saltarina->prev = NULL;
	while (argv[i])
	{
		//aux = saltarina;
		ayudante = malloc(sizeof(t_doublelist *));
		ayudante->content = atoi(argv[i]);
		ayudante->next = NULL;
		ayudante->prev = NULL;
		//ayudante->prev = saltarina;
		saltarina->next = ayudante;
		saltarina = ayudante;
		//saltarina->prev = aux;
		i ++;
		//ft_printlista(saltarina, 'e');
	}
	saltarina = start;
	i = 2;
	while (saltarina->next)
	{
		aux = saltarina;
		saltarina = saltarina->next;
		saltarina->prev = aux;
		// saltarina->content = atoi(argv[i]);
		// i ++;
	}
	
		printf("                                    venga prev == %d\n", saltarina->prev->prev->content);
	// ft_printlista(start, 'a');
	return(start);
}

int main(int argc, char **argv)
{
	t_doublelist	*start;

	start = guatafacgege(argv);
	//ft_printlista(start, 'A');
	// ft_printlista_prev(start, argc-1);
}