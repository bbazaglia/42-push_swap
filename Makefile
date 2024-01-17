NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRC = push_swap.c \
		assign_position.c
		check_input.c \
		linked_list.c \
		push_move.c \
		reverse_rotate_move.c \
		rotate_move.c \
		swap_move.c \
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