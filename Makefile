NAME = push_swap
BNAME = checker

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
	ft_indexing.c \
	ft_algo.c

BSRC =	\
	ft_atoi_bonus.c \
	ft_check_error_bonus.c \
	ft_is_duplicate_bonus.c \
	ft_clear_node_bonus.c	\
	ft_lstnew_bonus.c	\
	ft_lstadd_back_bonus.c \
	ft_lstsize_bonus.c \
	ft_split_bonus.c \
	ft_sort_least_bonus.c \
	op_a_bonus.c \
	op_b_bonus.c \
	ft_indexing_bonus.c \
	ft_algo_bonus.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	ft_valid_op_bonus.c \
	ft_strcmp_bonus.c \
	ft_add_op_bonus.c \
	ft_new_op_bonus.c \
	ft_instaction_bonus.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): push_swap.c $(OBJ)
	cc $(FLAG) $^ -o $@
$(BNAME): push_swap_bonus.c $(BOBJ)
	cc $(FLAG) $^ -o $@

bonus: $(BNAME)

$(OBJ): %.o: %.c push_swap.h
	cc $(FLAG) -c $< -o $@
$(BOBJ): %.o: %.c push_swap_bonus.h
	cc $(FLAG) -c $< -o $@


clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(BNAME)

re : fclean all