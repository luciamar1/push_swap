/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:20:21 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/27 20:48:33 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		order_nums(stack_b, stack_a);
	}
}
