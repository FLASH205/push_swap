/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:53:20 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/18 11:49:22 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_max(t_stack *stack_b)
{
	t_stack	*max;

	max = stack_b;
	while (stack_b)
	{
		if (max->nbr < stack_b->nbr)
			max = stack_b;
		stack_b = stack_b->next;
	}
	return (max);
}

void	ft_sort_large(t_stack **stack_b)
{
	t_stack	*max;
	t_stack	*tmp;
	size_t	dis;
	size_t	size;

	size = ft_lstsize(*stack_b);
	max = ft_find_max(*stack_b);
	tmp = (*stack_b);
	dis = 0;
	while (tmp && tmp != max)
	{
		dis++;
		tmp = tmp->next;
	}
	if (dis < size / 2)
	{
		while ((*stack_b) != max)
			rotate_b(stack_b);
	}
	else
	{
		while ((*stack_b) != max)
			reverse_rotate_b(stack_b);
	}
}

int	check_stack(t_stack	*stack)
{
	size_t	size;
	size_t	i;
	size_t	r;

	size = ft_lstsize(stack);
	i = 0;
	r = 0;
	while (i < size / 2)
	{
		if (stack->index > stack->next->index)
			r++;
		i++;
		stack = stack->next;
	}
	if (r > size / 3)
		return (0);
	return (1);
}

void	ft_algo(t_stack **stack_a, t_stack **stack_b, int range)
{
	size_t	i;
	int		r;

	i = 0;
	r = check_stack(*stack_a);
	while (*stack_a)
	{
		if (i >= (*stack_a)->index)
			(push_b(stack_a, stack_b), i++);
		else if (i + range >= (*stack_a)->index)
		{
			(push_b(stack_a, stack_b), rotate_b(stack_b));
			i++;
		}
		else if (r == 0)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
	while (*stack_b)
		(ft_sort_large(stack_b), push_a(stack_a, stack_b));
}
