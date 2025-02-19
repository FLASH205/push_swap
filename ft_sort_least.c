/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_least.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:28:26 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/19 09:13:02 by ybahmaz          ###   ########.fr       */
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
	if (f > s && f < t && s < t)
		swap_a(stack_a);
	else if (f > s && s < t && f > t)
		rotate_a(stack_a);
	else if (f > t && s > t && f < s)
		reverse_rotate_a(stack_a);
	else if (f > s && s > t && f > t)
		(swap_a(stack_a), reverse_rotate_a(stack_a));
	else if (f < s && s > t && f < t)
		(swap_a(stack_a), rotate_a(stack_a));
}

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

void	ft_sort_least(t_stack **stack_a, t_stack **stack_b)
{
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size <= 5)
	{
		move_min_to_top(stack_a);
		push_b(stack_a, stack_b);
		if (ft_lstsize(*stack_a) == 4)
		{
			move_min_to_top(stack_a);
			push_b(stack_a, stack_b);
		}
		ft_sort_three(stack_a);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
}
