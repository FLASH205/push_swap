/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_op_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:10:27 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/20 14:56:17 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_clear_op(t_op **op)
{
	t_op	*tmp;

	tmp = *op;
	while (tmp)
	{
		tmp = (*op)->next;
		free((*op)->op);
		free(*op);
		*op = tmp;
	}
}
