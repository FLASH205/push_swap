/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:55:27 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/14 13:31:37 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear_node(t_stack **lst)
{
	t_stack	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
