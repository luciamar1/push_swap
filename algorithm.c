/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/07 16:22:15 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_indice(t_dlist *list, t_dlist *min, int len)
{
	int	ind;
	int	l;

	//printf("llegas?  %d\n", len);
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

int	choose(int len)
{
	int	max;

	if (len < 100)
		max = 2;
	else if (len >= 100 && len < 300)
		max = 4;
	else
		max = 8;
	max = len / max;
	if (max == 0)
		max = 1;
	return (max);
}

void	if_less(t_dlist **stack_a, t_dlist **stack_b, int optim, int *head)
{
	if (optim < ft_len_dlist(*stack_a) / 2)
		while (optim --)
			rotate(stack_a, 'a');
	else
	{
		optim = ft_len_dlist(*stack_a) - optim;
		while (optim --)
			reverse_rotate(stack_a, 'a');
	}
	push_x(&(*stack_b), &(*stack_a), 'b');
	if (*head == 1)
		*head = 0;
	else
	{
		rotate(stack_b, 'b');
		*head = 1;
	}
	optim = 0;
}

void	check_if_rotate(t_dlist **a, t_dlist **b, int max, int *head)
{
	static int	optim = 0;

	if ((*a)->index <= max)
	{
		(if_less(a, b, optim, head));
		optim = 0;
	}
	else
	{
		optim ++;
		if (*a)
			(*a) = (*a)->next;
	}
}
