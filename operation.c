/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:19:38 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/03/09 13:24:47 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_doublelist {
	int					content;
	struct s_doublelist	*next;
	struct s_doublelist	*prev;
}	t_doublelist;

void	ft_printlista(t_doublelist *lista, char x)
{
	while (lista->next)
	{
		printf("printlista %c contenido == %d\n", x, lista->content);
		lista = lista->next;
	}
}

void	ft_freedoublelist(t_doublelist *lista)
{
	lista = lista->next;
	while (lista->next)
	{
		free(lista->prev);
		lista = lista->next;
	}
}

void	*doublylink_new(int content, t_doublelist **prevstack, int orden)
{
	t_doublelist	*new;

	new = malloc(sizeof(t_doublelist *));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	if (orden == 1)
	{
		new->prev = *prevstack;
		*prevstack = new;
		(*prevstack)->prev->next = new;
		return ("bien");
	}
	new->prev = NULL;
	return (new);
}

void	swap_a_or_b(t_doublelist  **stack)
{
	int	swap;

	swap = (*stack)->content;
	(*stack)->content = ((*stack)->next->content);
	(*stack)->next->content = swap;
}

void	swap_a_and_b(t_doublelist **stack_a, t_doublelist **stack_b)
{
	int	swap;

	swap = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = swap;
	if ((*stack_b)->content)
	{
		swap = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = swap;
	}
}

void	push_x(t_doublelist **stack_b, t_doublelist **stack_a)
{
	t_doublelist	*swap;
	
	swap = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	swap->next = *stack_b;
	*stack_b = swap;
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

t_doublelist	*build_lst(char **argv, int argc)
{
	t_doublelist	*head_a;
	t_doublelist	*init_a;
	int				i;

	i = 1;
	head_a = doublylink_new(atoi(argv[0]), NULL, 0);
	if (head_a == NULL)
		return (NULL);
	init_a = head_a;
	while (i < argc)
	{
		if (doublylink_new(atoi(argv[i++]), &head_a, 1) == NULL)
		{
			ft_freedoublelist(head_a);
			return (NULL);
		}
	}
	ft_printlista(init_a, 'A');
	return (init_a);
}

int	main(int argc, char **argv)
{
	t_doublelist	*head_a;
	t_doublelist	*init_a;
	t_doublelist	*init_b;
	t_doublelist	*head_b;

	if (argc == 1)
		return (1);
	head_a = build_lst(++argv, argc - 1);
	if (head_a == NULL)
		return (1);
	init_a = head_a;
	//init_b = head_b;
	push_x(&init_b, &init_a);
	ft_printlista(init_b, 'B');
	return (0);
}
