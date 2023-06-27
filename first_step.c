/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:20:26 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/27 16:33:18 by lucia-ma         ###   ########.fr       */
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
	if ((*b)->index < (max / 2))
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
				list = ((optim = 0), *a);
			}
			else
				list = ((optim ++), list->next);
		}
		max += aument;
	}
}
