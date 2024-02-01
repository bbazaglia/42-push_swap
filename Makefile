NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 
# -fsanitize=address

VPATH = source ./source/moves

INCLUDE = -I./include

SRC = assign_index.c \
		ft_split.c \
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

OBJ = obj

SRC_OBJ = $(SRC:%.c=$(OBJ)/%.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	@$(CC) $(CFLAGS) $(SRC_OBJ) -o $(NAME) 
	@echo "Compilation completed: $@"

$(OBJ)/%.o : %.c
	@mkdir -p $(dir $@)	
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) && printf "Compiling: $(notdir $<\n)"

clean: 
	@rm -rf $(OBJ)
	@echo "objects removed" 

fclean: clean
	@rm -f $(NAME)
	@echo "executable removed"

re: fclean all

.PHONY: all clean fclean re 

#checker

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

test1000: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l
