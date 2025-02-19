/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_op_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:14:06 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/19 12:00:20 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_valid_op(char *line)
{
	if (!ft_strcmp(line, "sa\n") && !ft_strcmp(line, "ra\n") && !ft_strcmp(line, "rra\n")
		&& !ft_strcmp(line, "pa\n") && !ft_strcmp(line, "sb\n") && !ft_strcmp(line, "rb\n")
		&& !ft_strcmp(line, "rrb\n") && !ft_strcmp(line, "pb\n") && !ft_strcmp(line, "ss\n")
		&& !ft_strcmp(line, "rrr\n") && !ft_strcmp(line, "rr\n"))
		return (write(2, "Error\n", 6), 0);
	return (1);
}
