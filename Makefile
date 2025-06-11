CC=cc
FLAGS=-Wall -Wextra -Werror -g
INCL=libft

SRCS=checks.c error.c free.c get_chunk.c get_cost.c get_index.c get_position.c \
	 init.c \
	 list_init.c list_utils.c push.c push_swap.c reverse_rotate.c rotate.c \
	 sorter.c swap.c

OBJS=$(SRCS:%.c=%.o)

LIBFT=libft/libft.a
NAME=push_swap

all: $(NAME)

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
