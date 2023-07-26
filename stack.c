/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:20:26 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/07/26 22:29:16 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stack_a(char **stack, t_dlist **stack_a)
{
	int		i;
	t_dlist	*head;
	int		ai;
	int		error;

	*stack_a = ((i = 0), NULL);
	ai = ft_atoi_any_characters(stack[i++], &error);
	if (error == 1 || ft_create_dlist(stack_a, ai) == 1)
		return (write(2, "Error\n", 6), 1);
	head = *stack_a;
	while (stack[i])
	{
		ai = ft_atoi_any_characters(stack[i++], &error);
		if (error == 1 || ft_create_dlist(stack_a, ai) == 1)
		{
			head->prev = *stack_a;
			(*stack_a)->next = head;
			(*stack_a) = (*stack_a)->next;
			return ((ft_freecharmatrix(stack)), 1);
		}
	}
	head->prev = *stack_a;
	(*stack_a)->next = head;
	(*stack_a) = (*stack_a)->next;
	return (ft_freecharmatrix(stack), 0);
}

void	put_indice(t_dlist *list, t_dlist *min, int len)
{
	int	ind;
	int	l;

	ind = 0;
	len = ft_len_dlist(list);
	while (len --)
	{
		l = ft_len_dlist(list);
		while (l-- && (list)->index != -1)
			list = (list)->next;
		min = (list);
		l = ft_len_dlist(list);
		while (l--)
		{
			if ((list)->content < min->content && (list)->index == -1)
				min = list;
			list = (list)->next;
		}
		if (min->index == -1)
			min->index = ind;
		ind ++;
	}
}
