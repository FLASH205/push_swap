/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:09:00 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/14 13:09:31 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_duplicate(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->nbr == num)
			return (write(2, "Error\n", 6), 0);
		stack = stack->next;
	}
	return (1);
}