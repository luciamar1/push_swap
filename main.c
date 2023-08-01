/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:13:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/27 20:55:55 by lucia-ma         ###   ########.fr       */
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

int	menores_equals(char **str, int *message)
{
	int	cont;
	int	equal;
	int	ok;

	cont = ((ok = 0), 0);
	while (str[cont])
	{
		equal = cont + 1;
		while (str[equal])
		{
			if (ft_atoi(str[cont]) == ft_atoi(str[equal]))
				return (*message = 1, 1);
			equal ++;
		}
		if (str[cont + 1])
			if (ft_atoi(str[cont]) > ft_atoi(str[cont + 1]))
				ok = 1;
		cont ++;
	}
	if (ok == 0)
		return (1);
	return (0);
}


int	ft_equals(char **str, int count)
{
	int equal;

	equal = count + 1; 
	while (str[equal])
	{
		if (ft_atoi(str[count]) == ft_atoi(str[equal]))
			return (1);
		equal ++;
	}
	return(0);
}

int ft_ordered(char **str)
{
	int count;

	count = 0;
	while(str[count])
	{
		if (str[count + 1])
			if (ft_atoi(str[count]) > ft_atoi(str[count + 1]))
				return(1);
		count ++;
	}
	return(0);
}

int	ft_duplicate_signs(char *str)
{	
	int count;

	count = 0;
	while(str[count])
	{
		if(str[count] == '+' || str[count] == '-')
		{
			if(count > 0 && (str[count - 1] != ' ' && (str[count - 1] < 9 || str[count - 1] > 13) && str[count - 1] != '"' ))
				return(1);
			count ++;
			if(str[count] == '+' || str[count] == '-')
				return(1);			
		}
		else
			count++;
	}
	return(0);
}

int	around_argv(char **str, int *ms)
{
	int count;

	count = 0;
	while(str[count])
	{
		if(ft_equals(str, count) == 1)
			return((*ms = 1), 1);
		if(ft_duplicate_signs(str[count]) == 1)
			return((*ms = 1), 1);
		if(ft_isalpha_str(str[count]) == 1)
			return((*ms = 1), 1);
		count ++;
	}
	if(ft_ordered(str) == 0)
			return(1);
	return(0);
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
	{
		array = create_stack(array, argv[counter++]);
	}
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
	ft_printf_dlist(stack_a);
	ft_clear_dlist(&stack_a);
	return (0);
}
