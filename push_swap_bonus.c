/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:14:00 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/20 17:44:11 by ybahmaz          ###   ########.fr       */
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

int	ft_is_sorted(t_stack *stack_a)
{
	t_stack	*tmpstk;

	tmpstk = stack_a;
	while (tmpstk && tmpstk->next)
	{
		if (tmpstk->nbr > tmpstk->next->nbr)
			return (0);
		tmpstk = tmpstk->next;
	}
	return (1);
}

int	ft_read_input(t_stack **stack_a, t_stack **stack_b, t_op **op)
{
	t_op	*optmp;
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_valid_op(line) == 0)
			return (free(line), get_next_line(-1),
				ft_clear_node(stack_a), ft_clear_op(op), 0);
		ft_add_op(op, ft_new_op(line));
		line = get_next_line(0);
	}
	optmp = *op;
	while (optmp)
	{
		ft_instaction(stack_a, stack_b, optmp);
		optmp = optmp->next;
	}
	if (ft_is_sorted(*stack_a) && *stack_b == NULL)
		(write(1, "OK\n", 3), ft_clear_op(op), ft_clear_node(stack_a));
	else
		(write(1, "KO\n", 3), ft_clear_op(op),
			ft_clear_node(stack_a), ft_clear_node(stack_b));
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_op	*op;
	int		i;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	op = NULL;
	i = 0;
	while (++i < argc)
	{
		if (ft_check_error(argv[i]) == 0)
			return (ft_clear_node(&stack_a), 1);
		if (split_argument(argv[i], &stack_a) == 0)
			return (ft_clear_node(&stack_a), 1);
	}
	if (ft_read_input(&stack_a, &stack_b, &op) == 0)
		return (1);
	return (0);
}
