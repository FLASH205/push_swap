/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:14:00 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/20 17:32:46 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_argument(char	*arg, t_stack **stack_a)
{
	int		cw;
	int		i;
	long	num;
	char	**arr;

	cw = count_w(arg, ' ');
	arr = ft_split(arg, ' ');
	if (!arr)
		return (0);
	i = 0;
	while (i < cw)
	{
		num = ft_atoi(arr[i]);
		if (num == 2147483648)
			return (ft_free(arr, cw), 0);
		if (ft_is_duplicate(*stack_a, (int)num) == 0)
			return (ft_free(arr, cw), 0);
		ft_lstadd_back(stack_a, ft_lstnew((int)num));
		i++;
	}
	ft_free(arr, i);
	return (1);
}

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort_number(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize(stack_a) <= 5)
		ft_sort_least(&stack_a, &stack_b);
	else
	{
		ft_indexing(&stack_a);
		if (ft_lstsize(stack_a) <= 100)
			ft_algo(&stack_a, &stack_b, 11);
		else
			ft_algo(&stack_a, &stack_b, 25);
	}
	ft_clear_node(&stack_a);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_check_error(argv[i]) == 0)
			return (ft_clear_node(&stack_a), 1);
		if (split_argument(argv[i], &stack_a) == 0)
			return (ft_clear_node(&stack_a), 1);
		i++;
	}
	if (ft_is_sorted(stack_a) == 0)
		ft_sort_number(stack_a, stack_b);
	else
		ft_clear_node(&stack_a);
	return (0);
}
