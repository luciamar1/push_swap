/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/05/22 16:09:44 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_indice(t_dlist *list, t_dlist *min, int len)
{
	int	ind;
	int	l;

	ind = 0;
	l = ft_len_dlist(list);
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
	max = len/max;
	if (max == 0)
		max = 1;
	return (max);
}

void	if_less(t_dlist **stack_a, t_dlist **stack_b, int optim, int *head)
{
	int	op;

	op = optim;
	while (op --)
		*stack_a = (*stack_a)->prev;
	if (optim < ft_len_dlist(*stack_a)/2)
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

void	check_if_rotate(t_dlist **a, t_dlist **b, int *optim)
{
	static int optim = 0;

}

void	push_20(t_dlist **a, t_dlist **b, int len, int head)
{
	int	max;
	int	aument;
	//int	optim;

	optim = 0;
	max = choose(len);
	aument = max;
	while (*a)
	{
		while (len --)
		{
			if ((*a)->index <= max)
			{
				optim = 0;
				(if_less(a, b, optim, &head));
			}
			else
			{
				optim ++;
				if (*a)
					(*a) = (*a)->next;
			}
		}
		if (*a)
			len = ft_len_dlist(*a);
		max += aument;
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
		if (stack_next->index != index )
			verif_next++;
		if (stack_prev->index != index )
			verif_prev++;
	}
	if (verif_prev < verif_next)
		return (0);
	else
		return (1);
}

void	order_nums_push_a(t_dlist **stack_a, t_dlist **stack_b, \
		t_dlist **list, int ind, int saltarin)
{
	int	len;

	len = ft_len_dlist(*list);
	if ((*list)->index == ind && saltarin < (len / 2))
		while (saltarin--)
			rotate(stack_b, 'b');
	else if ((*list)->index == ind && saltarin >= (len / 2))
	{
		saltarin = ft_len_dlist(*stack_b) - saltarin;
		while (saltarin--)
			reverse_rotate(stack_b, 'b');
	}
	push_x(stack_a, stack_b, 'a');
}

void order_nums(t_dlist **stack_b, t_dlist **stack_a)
{
	int ind, l, saltarin;
	t_dlist *list;
	
	l = ft_len_dlist(*stack_b);
	ind = l - 1;
	list = *stack_b;
	while (l--)
	{
		saltarin = 0;
		while (list->index != ind)
		{
			list = list->next;
			saltarin++;
		}
		order_nums_push_a(stack_a, stack_b, &list, ind, saltarin);
		if (*stack_b)
			list = *stack_b;
		ind--;
	}
}

void algorithm(t_dlist **stack_a, t_dlist **stack_b)
{
	int len;

	len = ft_len_dlist(*stack_a);
	put_indice(*stack_a, *stack_a, ft_len_dlist(*stack_a));
	if (len <= 5)
		select_algorithm(stack_a, stack_b);
	else
	{
		push_20(stack_a, stack_b, ft_len_dlist(*stack_a), 1);
		order_nums(stack_b, stack_a);
	}
	
}

