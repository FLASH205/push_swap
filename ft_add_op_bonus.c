/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_op_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:48:01 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/19 14:39:56 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_add_op(t_op **op, t_op *new)
{
	t_op	*last;

	if (!new)
		return ;
	if (*op == NULL)
	{
		*op = new;
		return ;
	}
	last = *op;
	while (last->next)
		last = last->next;
	last->next = new;
}
