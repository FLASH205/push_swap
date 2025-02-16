/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:34:45 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/14 18:14:37 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack **stack_b)
{
	t_stack	*f;
	t_stack	*s;

	f = (*stack_b);
	s = (*stack_b)->next;
	(*stack_b) = s;
	f->next = s->next;
	s->next = f;
	write(1, "sb\n", 3);
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*f;
	t_stack *l;
	
	f = (*stack_b);

	(*stack_b) = f->next;
	f->next = NULL;
	l = (*stack_b);
	while (l->next)
		l = l->next;
	l->next = f;
	write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack *l;
	t_stack	*f;
	t_stack *pl;

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
	write(1, "rrb\n", 4);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	write(1, "pb\n", 3);
}
