/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:14:31 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/19 17:42:01 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>    //?   Don't forget to remove this library!!!!!!!!!!!

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1
# endif

typedef struct s_stack
{
	int				nbr;
	size_t			index;
	struct s_stack	*next;
}					t_stack;

typedef	struct s_op
{
	char		*op;
	struct s_op	*next;
}	t_op;


char	*get_next_line(int fd);
char	*ft_strchr(char *str);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
t_stack	*ft_lstnew(int num);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_check_error(char *str);
int		ft_is_duplicate(t_stack *stack_a, int num);
long	ft_atoi(char *str);
void	ft_clear_node(t_stack **lst);
char	**ft_split(char *s, char c);
int		count_w(char *s, char c);
void	ft_free(char **split, int i);
size_t	ft_lstsize(t_stack *stack);
void	ft_sort_least(t_stack **stack_a, t_stack **stack_b);
void	swap_a(t_stack **stack_a);
void	rotate_a(t_stack **stack_a);
void	reverse_rotate_a(t_stack **stack_a);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	swap_b(t_stack **stack_b);
void	rotate_b(t_stack **stack_b);
void	reverse_rotate_b(t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	ft_indexing(t_stack **stack_a);
void	ft_algo(t_stack **stack_a, t_stack **stack_b, int range);
int		ft_valid_op(char *line);
int		ft_strcmp(char *s1, char *s2);
void	ft_add_op(t_op **op, t_op *new);
t_op	*ft_new_op(char *line);
void	ft_instaction(t_stack **stack_a, t_stack **stack_b, t_op *op);

#endif