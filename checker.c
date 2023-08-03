/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:13:37 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/08/03 21:57:04 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	menores_equals(char **str, int	*message)
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
	int	equal;

	equal = count + 1;
	while (str[equal])
	{
		if (ft_atoi(str[count]) == ft_atoi(str[equal]))
			return (1);
		equal ++;
	}
	return (0);
}

int	ft_ordered(char **str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count + 1])
			if (ft_atoi(str[count]) > ft_atoi(str[count + 1]))
				return (1);
		count ++;
	}
	return (0);
}

int	ft_duplicate_signs(char *str)
{	
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '+' || str[count] == '-')
		{
			if (count > 0 && (str[count - 1] != ' ' && (str[count - 1] < 9 || \
				str[count - 1] > 13) && str[count - 1] != '"' ))
				return (1);
			if (ft_strlen(str) == 1)
				return (1);
			count ++;
			if (str[count] == '+' || str[count] == '-')
				return (1);
		}
		else
			count++;
	}
	return (0);
}

int	around_argv(char **str, int	*ms)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (ft_equals(str, count) == 1)
			return ((*ms = 1), 1);
		if (ft_duplicate_signs(str[count]) == 1)
			return ((*ms = 1), 1);
		printf("iter == %d\n", ft_iterstr_intprove(str[count], &ft_issign, 0));
		if ((ft_iterstr_intprove(str[count], &ft_isdigit, 0) == 1) && \
			ft_iterstr_intprove(str[count], &ft_issign, 0) == 1)
			return ((*ms = 1), 1);
		count ++;
	}
	if (ft_ordered(str) == 0)
		return (1);
	return (0);
}
