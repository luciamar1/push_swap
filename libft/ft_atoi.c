/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:20:45 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/06/27 17:15:18 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				c;
	long long int	x;

	c = 1;
	x = 0;
	while (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if (ft_isalpha(*str))
			return (0);
		if (*str == '+' || *str == '-' || ft_isalpha(*str))
			if (*str++ == '-')
				c *= -1;
		while (*str <= '9' && *str >= '0')
			x = x * 10 + (*str++ - '0');


		if (x > 0x7fffffff && c == 1)
			return (-1);
		if (x > 0x80000000 && c == -1)
			return (0);
		return (c * x);
		str++;
	}
	return (0);
}

int	ft_atoi_chetao(char *str, int *error)
{
	int				c;
	long long int	x;

	c = 1;
	x = 0;
	while (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if (ft_isalpha(*str))
			return ((*error = 1), 1);
		if (*str == '+' || *str == '-' || ft_isalpha(*str))
			if (*str++ == '-')
				c *= -1;
		while (*str <= '9' && *str >= '0')
			x = x * 10 + (*str++ - '0');
		if (x > 0x7fffffff && c == 1)
			return ((*error = 1), 1);
		if (x > 0x80000000 && c == -1)
			return ((*error = 1), 1);
		return (c * x);
		str++;
	}
	return (0);
}

// int	ft_atoi_chetao(char *str, int *error)
// {
// 	int				c;
// 	unsigned int	x;
// 	char			*max;
// 	printf("kaka\n");
// 	max = str;
// 	c = 1;
// 	x = 0;
// 	while (*str)
// 	{
// 		while ((*str >= 9 && *str <= 13) || *str == ' ')
// 			str++;
// 		if (ft_isalpha(*str))
// 		{
// 			*error = 1;
// 			return (0);
// 		}
// 		if (*str == '+' || *str == '-' || ft_isalpha(*str))
// 			if (*str++ == '-')
// 				c *= -1;
// 		while (*str <= '9' && *str >= '0')
// 			x = x * 10 + (*str++ - '0');
// 		if (x > 0x7fffffff && c == 1)
// 		{
// 			*error = 1;
// 			return (-1);
// 		}
// 		if (x > 0x80000000 && c == -1)
// 		{
// 			*error = 1;
// 			return (0);
// 		}
// 		//printf("kaka %d\n", ft_strlen(max));
// 		if(ft_strlen(max) >= 19)
// 		{
// 			printf("kaka\n");
// 			*error = 1;
// 			return (0);
// 		}
// 		return (c * x);
// 		str++;
// 	}
// 	*error = 1;
// 	return (0);
// }
