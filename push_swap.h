/* ************************************************************************** */
/*		                                                             */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:16:39 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/05/22 17:13:15 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdarg.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_dlist
{
	int				content;
	int				index;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

int		ft_rec(char *str);
int		ft_atoi_any_characters(char *str, int *error);
int		create_stack_a(char **stack, t_dlist **stack_a);
void	push_b_nuevo(t_dlist **a, t_dlist **b, int len);
void	if_less(t_dlist **stack_a, t_dlist **stack_b, int optim, int *head);
int		ft_create_dlist(t_dlist **saltarina, int data);
int		ft_clear_dlist(t_dlist **list);
int		ft_len_dlist(t_dlist *stack);
void	ft_printf_dlist(t_dlist *list);
void	ft_printf_dlist_ind(t_dlist *list);
void	push_20(t_dlist **stack_a, t_dlist **stack_b, int len, int head);
void	order_nums(t_dlist **stack_b, t_dlist **stack_a);
void	algorithm(t_dlist **stack_a, t_dlist **stack_b);
void	reverse_rotate_a_b(t_dlist **stack_a, t_dlist **stack_b, char stack);
void	reverse_rotate(t_dlist **stack_a, char stack);
void	rotate(t_dlist **stack_a, char stack);
void	rotate_a_and_b(t_dlist **stack_a, t_dlist **stack_b, char stack);
int		swap_a_or_b(t_dlist **stack, char letter);
void	swap_a_and_b(t_dlist **stack_a, t_dlist **stack_b);
void	push_x(t_dlist **stack_b, t_dlist **stack_a, char stack);
void	put_indice(t_dlist *list, t_dlist *min, int len);
void	select_algorithm(t_dlist **stack_a, t_dlist **stack_b);
int		choose(int len);
void	check_if_rotate(t_dlist **a, t_dlist **b, int max, int *head);

#endif
