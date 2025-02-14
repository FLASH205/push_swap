/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:14:00 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/14 18:28:06 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_argument(char	*arg, t_stack **stack)
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
		if (ft_is_duplicate(*stack, (int)num) == 0)
			return (ft_free(arr, cw), 0);
		ft_lstadd_back(stack, ft_lstnew((int)num));
		i++;
	}
	ft_free(arr, i);
	return (1);
}

void	ft_sort_three(t_stack **stack)
{
	int	f;
	int	s;
	int	t;

	f = (*stack)->nbr;
	s = (*stack)->next->nbr;
	t = (*stack)->next->next->nbr;
	if (f > s && t > f)
		swap_a(stack);
	else if (f > s && s < t)
		rotate_a(stack);
	else if (f < s && s > t)
		reverse_rotate_a(stack);
	else if (f > s && s > t)
		(swap_a(stack), reverse_rotate_a(stack));
	else if (f < s && s > t)
		(swap_a(stack), rotate_a(stack));
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

void	ft_sort(t_stack **stack)
{
	size_t	size;

	size = ft_lstsize(*stack);
	if (size == 2)
		swap_a(stack);
	else if (size == 3)
		ft_sort_three(stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	int		i;

	if (argc == 1)
		return (0);
	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_check_error(argv[i]) == 0)
			return (ft_clear_node(&stack), 1);
		if (split_argument(argv[i], &stack) == 0)
			return (ft_clear_node(&stack), 1);
		i++;
	}
	if (ft_is_sorted(stack) == 0)
		ft_sort(&stack);
	ft_clear_node(&stack);
	return (0);
}
