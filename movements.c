/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:27:02 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/05/22 18:29:23 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_dlist **stack_a, char stack)
{
	if (!*stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
	if (stack == 'a')
		write(1, "rra\n", 4);
	if (stack == 'b')
		write(1, "rrb\n", 4);
}

void	rotate(t_dlist **stack_a, char stack)
{
	if (*stack_a)
		*stack_a = (*stack_a)->next;
	if (stack == 'a')
		write(1, "ra\n", 3);
	if (stack == 'b')
		write(1, "rb\n", 3);
}

int	swap_a_or_b(t_dlist	**stack, char letter)
{
	int	swap;

	if (!*stack)
		return (1);
	swap = (*stack)->content;
	(*stack)->content = ((*stack)->next->content);
	(*stack)->next->content = swap;
	swap = (*stack)->index;
	(*stack)->index = ((*stack)->next->index);
	(*stack)->next->index = swap;
	if (letter == 'a')
		write(1, "sa\n", 3);
	if (letter == 'b')
		write(1, "sb\n", 3);
	return (0);
}

void	if_else(t_dlist **stack_b, t_dlist **stack_a, t_dlist *swap)
{
	if (ft_len_dlist(*stack_a) == 1)
		*stack_a = NULL;
	else
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = swap->prev;
		(*stack_a)->prev->next = *stack_a;
	}
	if (*stack_b)
	{
		swap->prev = (*stack_b)->prev;
		swap->next = (*stack_b);
		(*stack_b)->prev->next = swap;
		(*stack_b)->prev = swap;
		*stack_b = swap;
	}
	else
	{
		*stack_b = swap;
		(*stack_b)->next = (*stack_b);
		(*stack_b)->prev = (*stack_b);
	}
}

void	push_x(t_dlist **stack_b, t_dlist **stack_a, char stack)
{
	t_dlist	*swap;

	swap = *stack_a;
	if_else(stack_b, stack_a, swap);
	if (stack == 'a')
		write(1, "pa\n", 3);
	if (stack == 'b')
		write(1, "pb\n", 3);
}
