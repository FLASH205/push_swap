NAME = push_swap
FLAG = -Wextra -Werror -Wall
SRC =	\
	ft_atoi.c \
	ft_check_error.c \
	ft_is_duplicate.c \
	ft_clear_node.c	\
	ft_lstnew.c	\
	ft_lstadd_back.c \
	ft_lstsize.c \
	ft_split.c \
	ft_sort_least.c \
	op_a.c \
	op_b.c \
	move_min_to_top.c \
	ft_indexing.c \
	ft_algo.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): push_swap.c $(OBJ)
	cc $(FLAG) $^ -o $@

%.o: %.c push_swap.h
	cc $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all