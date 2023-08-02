/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:13:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/08/02 15:13:57 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	fre(void)
// {
// 	system("leaks -q push_swap");
// }

int	ft_atoi_push_swap(char *str, int *error)
{
	int				c;
	long long int	x;
	char			*max;

	c = ((max = str), (x = 0), 1);
	while (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if ((*str == '+' || *str == '-' ))
		{
			if (*str == '-')
				c = c * -1;
			str ++;
		}
		while (*str <= '9' && *str >= '0')
			x = x * 10 + (*str++ - '0');
		if ((x > 0x80000000 && c == -1) || (x > 0x7fffffff && c == 1) \
			|| ft_strlen(max) >= 19)
			return ((*error = 1), 0);
		return (c * x);
		str++;
	}
	return (*error = 1, 0);
}

char	*create_stack(char *old, char *new)
{
	char	*array;
	char	*space;

	space = ft_strjoin(old, " ");
	array = ft_strjoin(space, new);
	free(old);
	free(space);
	return (array);
}

char	**checker(int argc, char **argv, int *message)
{
	char	**stack;
	char	*array;
	int		counter;

	if (argc == 1)
		return (NULL);
	counter = 2;
	array = ft_strdup(argv[1]);
	while (argv[counter])
		array = create_stack(array, argv[counter++]);
	counter = 0;
	stack = ft_split(array, ' ');
	if (around_argv(stack, message) == 1)
	{
		free(array);
		ft_freecharmatrix(stack);
		return (NULL);
	}
	free(array);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	char	**stack;
	int		message;

	message = 0;
	stack = checker(argc, argv, &message);
	if (stack == NULL)
	{
		if (message == 1)
			write(2, "Error\n", 6);
		return (1);
	}
	stack_b = NULL;
	if (create_stack_a(stack, &stack_a, &message) == 1)
	{
		if (message == 1)
			write(2, "Error\n", 6);
		if (stack_a)
			ft_clear_dlist(&stack_a);
		return (1);
	}
	algorithm(&stack_a, &stack_b);
	ft_clear_dlist(&stack_a);
	return (0);
}
