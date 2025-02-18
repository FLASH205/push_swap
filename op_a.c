/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:34:45 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/18 14:53:32 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*f;
	t_stack	*s;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	f = (*stack_a);
	s = (*stack_a)->next;
	(*stack_a) = s;
	f->next = s->next;
	s->next = f;
	write(1, "sa\n", 3);
}

void	rotate_a(t_stack **stack_a)
{
	t_stack	*f;
	t_stack	*l;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	f = (*stack_a);
	(*stack_a) = f->next;
	f->next = NULL;
	l = (*stack_a);
	while (l->next)
		l = l->next;
	l->next = f;
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*l;
	t_stack	*f;
	t_stack	*pl;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	l = (*stack_a);
	while (l->next)
		l = l->next;
	f = (*stack_a);
	pl = (*stack_a);
	while (pl->next != l)
		pl = pl->next;
	(*stack_a) = l;
	l->next = f;
	pl->next = NULL;
	write(1, "rra\n", 4);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (stack_b == NULL || !*stack_b)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	write(1, "pa\n", 3);
}
