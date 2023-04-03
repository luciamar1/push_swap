/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:16:39 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/04/03 12:27:51 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
    int content;
    struct s_dlist *next;
    struct s_dlist *prev;
}   t_dlist;

void    push_20(t_dlist **stack_a, t_dlist **stack_b, int max);
void    order_nums(t_dlist **stack_b, t_dlist **stack_a);
void    algorithm(t_dlist **stack_a, t_dlist **stack_b);
void    reverse_rotate_a_b(t_dlist **stack_a, t_dlist **stack_b);
void    reverse_rotate(t_dlist **stack_a);
void    rotate(t_dlist **stack_a);
void    rotate_a_and_b(t_dlist **stack_a, t_dlist **stack_b);
int     swap_a_or_b(t_dlist  **stack);
void    swap_a_and_b(t_dlist **stack_a, t_dlist **stack_b);
void    push_x(t_dlist **stack_b, t_dlist **stack_a);

#endif