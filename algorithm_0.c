/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/07 21:24:03 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_less_push_b(t_dlist **a, t_dlist **b, int optim, int max)
{
	int			len;

	len = ft_len_dlist(*a);
	if (optim <= len / 2)
		while (optim --)
			rotate(a, 'a');
	else
	{
		optim = len - optim;
		while (optim --)
			reverse_rotate(a, 'a');
	}
	push_x(b, a, 'b');
	if ((*b)->index < (max/2))
		rotate(b, 'b');
}

void	push_b_nuevo(t_dlist **a, t_dlist **b, int len)
{
	int		max;
	t_dlist	*list;
	int		optim;
	int		aument;

	max = choose(len);
	aument = max;
	//printf(" %p\n ", *b);
	while (*a)
	{
		list = *a;
		optim = 0;
		len = ft_len_dlist(*a);
		while (len--)
		{
			if (list->index <= max)
			{
				if_less_push_b(a, b, optim, max);
				optim = 0;
				list = *a;
			}
			else
			{
				optim ++;
				list = list->next;
			}
		}
		max += aument;
	}
}

void	push_20(t_dlist **a, t_dlist **b, int len, int head)
{
	int		max;
	int		aument;
	t_dlist	*list;
	int		optim;

	optim = 0;
	list = *a;
	max = choose(len);
	aument = max;
	while (*a)
	{
		while (len --)
		{
			if (list->index <= max)
			{
				(if_less(a, b, optim, &head));
				optim = 0;
			}
			else
			{
				optim ++;
				if (list)
					list = list->next;
			}
		}
		if (*a)
			len = ft_len_dlist(*a);
		list = *a;
		max = max + aument;
	}
}

int	ft_optim(int index, t_dlist *stack_next)
{
	t_dlist	*stack_prev;
	int		verif_next;
	int		verif_prev;

	stack_prev = stack_next;
	verif_next = 0;
	verif_prev = 0;
	while (stack_next->index != index && stack_prev->index != index)
	{
		stack_next = stack_next->next;
		if (stack_next->index != index)
			verif_next++;
		if (stack_prev->index != index)
			verif_prev++;
	}
	if (verif_prev < verif_next)
		return (0);
	else
		return (1);
}


void	order_nums_push_a(t_dlist **stack_a, t_dlist **stack_b, \
		t_dlist **list, int ind)
{
	int					len;
	int					saltarin;
	static int			less = 0;

	saltarin = 0;
	len = ft_len_dlist(*list);
	while (len --)
	{
		if((*list)->index == ind)
		{
			less = 0;
			break;
		}
		if((*list)->index == ind - 1 && less == 0)
		{
			less ++;
			break;
		}
		if((*list)->index == ind + 1)
		{
			less = 0;
			break;
		}
		*list = ((saltarin++), (*list)->next);
	}
	len = ft_len_dlist(*list);
	if (saltarin < (len / 2))
		while (saltarin--)
			rotate(stack_b, 'b');
	else
	{
		saltarin = ft_len_dlist(*stack_b) - saltarin;
		while (saltarin--)
			reverse_rotate(stack_b, 'b');
	}
	push_x(stack_a, stack_b, 'a');
	if((*stack_a)->index == ind + 1)
	{
		swap_a_or_b(stack_a, 'a');
	}
}

void	order_nums(t_dlist **stack_b, t_dlist **stack_a)
{
	int		ind;
	int		l;
	t_dlist	*list;

	l = ft_len_dlist(*stack_b);
	ind = l - 1;
	list = *stack_b;
	while (l--)
	{
		order_nums_push_a(stack_a, stack_b, &list, ind);
		if (*stack_b)
			list = *stack_b;
		ind--;
	}
}

void	algorithm(t_dlist **stack_a, t_dlist **stack_b)
{
	int	len;

	len = ft_len_dlist(*stack_a);
	put_indice(*stack_a, *stack_a, 0);
	if (len <= 5)
		select_algorithm(stack_a, stack_b);
	else
	{
		push_b_nuevo(stack_a, stack_b, ft_len_dlist(*stack_a));
		//ft_//printf_dlist_ind(*stack_b);
		order_nums(stack_b, stack_a);
		//ft_printf_dlist_ind(*stack_a);
	}
}
