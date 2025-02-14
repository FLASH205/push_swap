/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:09:24 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/14 13:06:04 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (write(2, "Error\n", 6), 0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == ' ')
				return (write(2, "Error\n", 6), 0);
			i++;
		}
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	return (1);
}
