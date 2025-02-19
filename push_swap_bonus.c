/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:14:00 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/19 18:17:45 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	t_op	*op;
	int		i;
	char	*line;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	op = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_check_error(argv[i]) == 0)
			return (ft_clear_node(&stack_a), 1);
		if (split_argument(argv[i], &stack_a) == 0)
			return (ft_clear_node(&stack_a), 1);
		i++;
	}
	line = get_next_line(0);
	while (line)
	{
		if (ft_valid_op(line) == 0)
			return (free(line), ft_clear_node(&stack_a), 1);
		ft_add_op(&op, ft_new_op(line));
		line = get_next_line(0);
	}
	while (op)
	{
		ft_instaction(&stack_a, &stack_b, op);
		op = op->next;
	}
	//t_stack *lst = stack_a;
	//while (lst)
	//{
	//	printf("%d ", lst->nbr);
	//	lst = lst->next;
	//}
	if (ft_is_sorted(stack_a) && stack_b == NULL)
		(write(1, "OK\n", 3), ft_clear_node(&stack_a));
	else
		(write(1, "KO\n", 3), ft_clear_node(&stack_a));
	//if (ft_is_sorted(stack_a) == 0)
	//	ft_sort_number(stack_a, stack_b);
	//else
	//	(write(1, "OK\n", 3), ft_clear_node(&stack_a));
	return (0);
}
