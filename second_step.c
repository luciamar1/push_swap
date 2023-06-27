/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:20:26 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/27 20:42:18 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_ind_to_a(t_dlist **list, int *less, int ind, int *saltarin)
{
	int	len;

	len = ft_len_dlist(*list);
	while (len --)
	{
		if ((*list)->index == ind)
		{
			less = 0;
			break ;
		}
		if ((*list)->index == ind - 1 && less == 0)
		{
			less ++;
			break ;
		}
		if ((*list)->index == ind + 1)
		{
			less = 0;
			break ;
		}
		*list = (((*saltarin)++), (*list)->next);
	}
	return (0);
}

void	order_nums_push_a(t_dlist **stack_a, t_dlist **stack_b, \
		t_dlist **list, int ind)
{
	int					len;
	int					saltarin;
	static int			less = 0;

	saltarin = 0;
	order_ind_to_a(list, &less, ind, &saltarin);
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
	if ((*stack_a)->index == ind + 1)
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
