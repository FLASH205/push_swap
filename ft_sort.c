/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:28:26 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/16 22:28:26 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	int	f;
	int	s;
	int	t;

	f = (*stack_a)->nbr;
	s = (*stack_a)->next->nbr;
	t = (*stack_a)->next->next->nbr;
	if (f > s && f < t && s < t)		//!	sa
		swap_a(stack_a);
	else if (f > s && s < t && f > t)	//!	ra
		rotate_a(stack_a);
	else if (f > t && s > t && f < s)	//!	rra
		reverse_rotate_a(stack_a);	
	else if (f > s && s > t && f > t)			//! sa	rra
		(swap_a(stack_a), reverse_rotate_a(stack_a));
	else if (f < s && s > t && f < t)	//!	sa	ra
		(swap_a(stack_a), rotate_a(stack_a));
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else
	{
		while (size > 3)
		{
			move_min_to_top(stack_a);
			push_b(stack_a, stack_b);
			size--;
		}
		ft_sort_three(stack_a);
		size = ft_lstsize(*stack_b);
		while (*stack_b)
			push_a(stack_a, stack_b);
	}
	//* else if (size <= 5)
	//* {
	//* 	move_min_to_top(stack_a);
	//* 	push_b(stack_a, stack_b);
	//* 	if (ft_lstsize(*stack_a) == 4)
	//* 	{
	//* 		move_min_to_top(stack_a);
	//* 		push_b(stack_a, stack_b);
	//* 	}
	//* 	ft_sort_three(stack_a);
	//* 	push_a(stack_a, stack_b);
	//* 	push_a(stack_a, stack_b);
	//* }
}
