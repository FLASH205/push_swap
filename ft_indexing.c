/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:52:42 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/17 15:05:03 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexing(t_stack **stack_a)
{
	t_stack	*lst;
	t_stack	*current;
	int		i;

	lst = (*stack_a);
	while (lst)
	{
		current = (*stack_a);
		i = 0;
		while (current)
		{
			if (lst->nbr > current->nbr)
				i++;
			current = current->next;
		}
		lst->index = i;
		lst = lst->next;
	}
}
