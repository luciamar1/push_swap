/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/05/23 17:10:14 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_20(t_dlist **a, t_dlist **b, int len, int head)
{
	int	max;
	int	aument;

	max = choose(len);
	aument = max;
	while (*a)
	{
		while (len --)
		{
			check_if_rotate(a, b, max, &head);
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
	int			len;
	int			saltarin;
	static int	optim = 0;

	saltarin = 0;
	len = ft_len_dlist(*list);
	if (optim == 1)
		optim = ((ind ++), 2);
	else if (optim == 2)
		optim = ((ind --), 2);
	while ((*list)->index == ind || ((*list)->index == ind - 1 && optim != 2))
		*list = ((saltarin++), (*list)->next);
	if ((*list)->index == ind - 1)
		optim = 1;
	if (saltarin < (len / 2))
		while (saltarin--)
			rotate(stack_b, 'b');
	else if (saltarin >= (len / 2))
	{
		saltarin = ft_len_dlist(*stack_b) - saltarin;
		while (saltarin--)
			reverse_rotate(stack_b, 'b');
	}
	push_x(stack_a, stack_b, 'a');
	if(optim == 1)
		swap_a_or_b(stack_a, 'a');
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
	put_indice(*stack_a, *stack_a, ft_len_dlist(*stack_a));
	if (len <= 5)
		select_algorithm(stack_a, stack_b);
	else
	{
		push_20(stack_a, stack_b, ft_len_dlist(*stack_a), 1);
		order_nums(stack_b, stack_a);
	}
}
