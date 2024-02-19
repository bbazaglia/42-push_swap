# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 14:25:58 by bbazagli          #+#    #+#              #
#    Updated: 2024/02/19 10:44:04 by bbazagli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 
# -fsanitize=address

VPATH = sort stack checker_bonus

INCLUDE = -I./include -I ./LIBFT/include

LIBFT = ./LIBFT/libft.a

SRC = assign_index.c \
		free_args.c \
		cheapest_move.c \
		check_input.c \
		get_cost.c \
		get_position.c \
		stack.c \
		move_push.c \
		move_reverse_rotate.c \
		move_rotate.c \
		move_swap.c \
		main.c \
		sort.c 

SRC_BONUS = assign_index.c \
		free_args.c \
		cheapest_move.c \
		check_input.c \
		get_cost.c \
		get_position.c \
		stack.c \
		move_push.c \
		move_reverse_rotate.c \
		move_rotate.c \
		move_swap.c \
		sort.c \
		check_sort.c \
		push_bonus.c \
		reverse_rotate_bonus.c \
		rotate_bonus.c \
		swap_bonus.c 

OBJ = obj

SRC_OBJ = $(SRC:%.c=$(OBJ)/%.o)

SRC_OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ)/%.o)

all: libft $(NAME)

$(NAME): libft $(SRC_OBJ) 
	@$(CC) $(CFLAGS) $(SRC_OBJ) $(LIBFT) -o $(NAME) 
	@echo "Compilation completed: $@"

bonus: libft $(SRC_OBJ_BONUS) 
	@$(CC) $(CFLAGS) $(SRC_OBJ_BONUS) $(LIBFT) -o $(BONUS) 
	@echo "Compilation completed: $@"

a.out: libft $(SRC_OBJ_BONUS) 
	@$(CC) $(CFLAGS) $(SRC_OBJ_BONUS) $(LIBFT) -o $@

libft:
	@make -C ./LIBFT

$(OBJ)/%.o : %.c
	@mkdir -p $(dir $@)	
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) && printf "Compiling: $(notdir $<\n)"

clean: 
	@make -C ./LIBFT clean --silent
	@rm -rf $(OBJ)
	@echo "objects removed" 

fclean: clean
	@make -C ./LIBFT fclean --silent 
	@rm -f $(NAME) $(BONUS) a.out
	@echo "executable removed"

re: fclean all

.PHONY: all clean fclean re libft bonus

#rules for checker_bonus
checker2: $(NAME) bonus
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

checker3: $(NAME) bonus
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
	
checker5: $(NAME) bonus
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

checker100: $(NAME) bonus	
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	./push_swap $(ARG) | ./checker $(ARG) 
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

checker500: $(NAME) bonus	
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l


# rules for checker_linux
test2: $(NAME) 
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test3: $(NAME) 
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test5: $(NAME) 
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100: $(NAME) 
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500: $(NAME) 
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
