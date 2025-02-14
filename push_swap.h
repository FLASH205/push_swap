/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:14:31 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/14 18:03:02 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>    //TODO!   Don't forget to remove this library!!!!!!!!!!!

typedef struct s_stack
{
	int				nbr;
	size_t			index;
	struct s_stack	*next;
}					t_stack;

t_stack	*ft_lstnew(int num);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_check_error(char *str);
int		ft_is_duplicate(t_stack *stack, int num);
long	ft_atoi(char *str);
void	ft_clear_node(t_stack **lst);
char	**ft_split(char *s, char c);
int		count_w(char *s, char c);
void	ft_free(char **split, int i);
int		ft_lstsize(t_stack *stack);
void	swap_a(t_stack **stack);
void	rotate_a(t_stack **stack);
void	reverse_rotate_a(t_stack **stack);

#endif