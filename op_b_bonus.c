/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:34:45 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/19 10:47:17 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_b(t_stack **stack_b)
{
	t_stack	*f;
	t_stack	*s;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	f = (*stack_b);
	s = (*stack_b)->next;
	(*stack_b) = s;
	f->next = s->next;
	s->next = f;
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*f;
	t_stack	*l;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	f = (*stack_b);
	(*stack_b) = f->next;
	f->next = NULL;
	l = (*stack_b);
	while (l->next)
		l = l->next;
	l->next = f;
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*l;
	t_stack	*f;
	t_stack	*pl;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	l = (*stack_b);
	while (l->next)
		l = l->next;
	f = (*stack_b);
	pl = (*stack_b);
	while (pl->next != l)
		pl = pl->next;
	(*stack_b) = l;
	l->next = f;
	pl->next = NULL;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (stack_a == NULL || !*stack_a)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
}
