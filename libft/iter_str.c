/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia-ma <lucia-ma@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:21:09 by lucia-ma          #+#    #+#             */
/*   Updated: 2023/08/03 21:40:34 by lucia-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iterstr_intprove(char *str, int (*f)(int), int prove)
{
	while (*str)
	{
		//printf("funcion iter == %d char == %c\n", f(*str), *str);
		if (f(*str) == prove)
			return (1);
		str++;
	}
	return (0);
}
