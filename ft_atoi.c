/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:37:53 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/14 12:35:06 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	int			i;
	int			s;
	long	r;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	s = 1;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		if ((r > 2147483647 && s == 1) || (r > 2147483648 && s == -1))
			return (write(2, "Error\n", 6), 2147483648);
		i++;
	}
	r = r * s;
	return (r);
}
