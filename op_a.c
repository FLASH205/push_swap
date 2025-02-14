/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:34:45 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/14 18:14:37 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack)
{
	t_stack	*f;
	t_stack	*s;

	f = (*stack);
	s = (*stack)->next;
	(*stack) = s;
	f->next = s->next;
	s->next = f;
	write(1, "sa\n", 3);
}

void	rotate_a(t_stack **stack)
{
	t_stack	*f;
	t_stack *l;
	
	f = (*stack);

	(*stack) = f->next;
	f->next = NULL;
	l = (*stack);
	while (l->next)
		l = l->next;
	l->next = f;
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_stack **stack)
{
	t_stack *l;
	t_stack	*f;
	t_stack *pl;

	l = (*stack);
	while (l->next)
		l = l->next;
	f = (*stack);
	pl = (*stack);
	while (pl->next != l)
		pl = pl->next;
	(*stack) = l;
	l->next = f;
	pl->next = NULL;
	write(1, "rra\n", 4);
}
