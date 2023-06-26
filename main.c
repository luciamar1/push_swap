/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:13:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/26 16:18:10 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_any_characters(char *str, int *error)
{
	int				c;
	long long int	x;
	char			*max;

	max = str;
	c = 1;
	x = 0;
	while (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if (ft_isalpha(*str))
			return ((*error = 1), 0);
		if (*str == '+' || *str == '-' || ft_isalpha(*str))
			return ((*error = 1), 1);
		while (*str <= '9' && *str >= '0')
			x = x * 10 + (*str++ - '0');
		if (x > 0x7fffffff && c == 1)
			return ((*error = 1), 1);
		if (x > 0x80000000 && c == -1)
			return ((*error = 1), 0);

		if(ft_strlen(max) >= 19)
		{
			*error = 1;
			return (0);
		}
		
		return (c * x);
		str++;
	}
	*error = 1;
	return (0);
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


int	menores_equals(char **str)
{
	int cont;
	int	equal;
	int	ok;

	ok = 0;
	cont = 0;
	while(str[cont])
	{
		equal = cont + 1;
		while(str[equal])
		{
			if(ft_atoi(str[cont]) == ft_atoi(str[equal]))
				return(1);
			equal ++;

		}
		if(str[cont + 1])
		{
			if(ft_atoi(str[cont]) > ft_atoi(str[cont + 1]))
				ok = 1;
		}
		cont ++;
	}
	if(ok == 0)
		return(1);
	return(0);
}

char	**checker(int argc, char **argv)
{
	char	**stack;
	char	*array;
	int		counter;

	if (argc == 1)
		return (NULL);
	counter = 2;
	array = ft_strdup(argv[1]);
	while (argv[counter])
	{
		array = create_stack(array, argv[counter++]);
	}
	counter = 0;
	while(array[counter] && (ft_isdigit(array[counter]) == 1 || array[counter] == ' '))
	{
		counter ++;
	}
	if(array[counter])
	{
		free(array);
		return(NULL);
	}
	stack = ft_split(array, ' ');
	if(menores_equals(stack) == 1)
	{
		free(array);
		ft_freecharmatrix(stack);
		return (NULL);
	}
	free(array);
	return (stack);
}

int	create_stack_a(char **stack, t_dlist **stack_a)
{
	int		i;
	t_dlist	*head;
	int		ai;
	int		error;

	i = 0;
	*stack_a = NULL;
	ai = ft_atoi_any_characters(stack[i++], &error);
	if (error == 1 || ft_create_dlist(stack_a, ai) == 1)
	{
		
		return (1);
	}
	head = *stack_a;
	while (stack[i])
	{
		ai = ft_atoi_any_characters(stack[i++], &error);
		if (error == 1 || ft_create_dlist(stack_a, ai) == 1)
		{
			ft_freecharmatrix(stack);
			return (1);
		}
	}
	head->prev = *stack_a;
	(*stack_a)->next = head;
	(*stack_a) = (*stack_a)->next;
	return (0);
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	char	**stack;

	stack = checker(argc, argv);
	if (stack == NULL)
		return (1);
	stack_b = NULL;
	create_stack_a(stack, &stack_a);
	ft_freecharmatrix(stack);
	algorithm(&stack_a, &stack_b);
	//ft_printf_dlist_ind(stack_a);
	ft_clear_dlist(&stack_a);
}
