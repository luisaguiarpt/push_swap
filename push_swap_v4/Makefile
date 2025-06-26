CC=cc
FLAGS=-Wall -Wextra -Werror -g
INCL=libft

SRCS=checks.c \
	 core_utils.c \
	 error.c \
	 free.c \
	 index.c \
	 moves.c \
	 push.c \
	 push_swap.c \
	 reverse_rotate.c \
	 rotate.c \
	 sort.c \
	 sort_cost.c \
	 sort_init.c \
	 sort_small.c \
	 sort_utils.c \
	 stack.c \
	 stack_utils.c \
	 swap.c
B_SRCS=checker.c \
	   checks.c \
	   core_utils.c \
	   error.c \
	   free.c \
	   index.c \
	   moves.c \
	   push.c \
	   reverse_rotate.c \
	   rotate.c \
	   sort.c \
	   sort_cost.c \
	   sort_init.c \
	   sort_small.c \
	   sort_utils.c \
	   stack.c \
	   stack_utils.c \
	   swap.c

OBJS=$(SRCS:%.c=%.o)
B_OBJS=$(B_SRCS:%.c=%.o)

LIBFT=libft/libft.a
NAME=push_swap
CHECKER=checker

all: $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(B_OBJS)
	$(CC) $(FLAGS) $(B_OBJS) $(LIBFT) -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INCL)

$(LIBFT):
	make -C libft/ all

clean:
	rm -rf $(OBJS)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
