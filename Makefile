NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 
# check leaks: -fsanitize=address

SRC = assign_index.c \
		cheapest_move.c \
		check_input.c \
		get_cost.c \
		get_position.c \
		linked_list.c \
		move_push.c \
		move_reverse_rotate.c \
		move_rotate.c \
		move_swap.c \
		push_swap.c \
		sort.c \
		utils.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 