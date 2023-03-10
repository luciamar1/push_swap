/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:19:38 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/03/10 20:23:51 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_doublelist {
	int					content;
	struct s_doublelist	*next;
	struct s_doublelist	*prev;
}	t_doublelist;

t_doublelist	*ft_lstnew(void *content)
{
	t_doublelist	*lista;

	lista = (void *)malloc(sizeof(t_doublelist));
	if (lista == NULL)
		return (lista);
	lista->content = content;
	lista->next = NULL;
	return (lista);
}


int main(int argc, char argv)
{
    
}