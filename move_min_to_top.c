/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min_to_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:42:24 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/18 12:40:29 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min(t_stack *stack_a)
{
	t_stack	*min;

	min = stack_a;
	while (stack_a)
	{
		if (min->nbr > stack_a->nbr)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

void	move_min_to_top(t_stack **stack_a)
{
	t_stack	*min;
	t_stack	*tmp;
	size_t	size;
	size_t	dis;

	min = ft_find_min(*stack_a);
	size = ft_lstsize(*stack_a);
	dis = 0;
	tmp = (*stack_a);
	while (tmp && tmp != min)
	{
		dis++;
		tmp = tmp->next;
	}
	if (dis < size / 2)
	{
		while ((*stack_a) != min)
			rotate_a(stack_a);
	}
	else
	{
		while ((*stack_a) != min)
			reverse_rotate_a(stack_a);
	}
}
