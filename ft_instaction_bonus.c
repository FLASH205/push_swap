/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instaction_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:19:34 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/20 09:22:59 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_instaction(t_stack **stack_a, t_stack **stack_b, t_op *op)
{
	if (ft_strcmp(op->op, "rra\n"))
		reverse_rotate_a(stack_a);
	else if (ft_strcmp(op->op, "sa\n"))
		swap_a(stack_a);
	else if (ft_strcmp(op->op, "ra\n"))
		rotate_a(stack_a);
	else if (ft_strcmp(op->op, "pa\n"))
		push_a(stack_a, stack_b);
	else if (ft_strcmp(op->op, "rrb\n"))
		reverse_rotate_b(stack_b);
	else if (ft_strcmp(op->op, "sb\n"))
		swap_b(stack_b);
	else if (ft_strcmp(op->op, "rb\n"))
		rotate_b(stack_b);
	else if (ft_strcmp(op->op, "pb\n"))
		push_b(stack_a, stack_b);
	else if (ft_strcmp(op->op, "ss\n"))
		(swap_a(stack_a), swap_b(stack_b));
	else if (ft_strcmp(op->op, "rr\n"))
		(rotate_a(stack_a), rotate_b(stack_b));
	else if (ft_strcmp(op->op, "rrr\n"))
		(reverse_rotate_a(stack_a), reverse_rotate_b(stack_b));
}
