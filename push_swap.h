#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// everytime is perfomed an operation that modifies the list, update the head and tail pointer as necessary
typedef struct s_stack_list
{
	t_stack_node		*head;
	t_stack_node		*tail;
}						t_stack_list;

// check functions
void					check_input(int argc, char **argv);
void					check_characters(char *argv);
void					check_limit(char *argv);
void					check_double(t_stack_list *stack);
void					print_error(void);

// linked list functions
t_stack_list			*create_stack(int argc, char **argv);
void					add_node(t_stack_list *stack, int value);
void					clear_stack(t_stack_list *stack);
int						stack_length(t_stack_list *stack);

// asign the current and target position of the nodes in the stack
void					assign_position(t_stack_list *stack);
t_stack_node			*merge_sorted_lists(t_stack_node *a, t_stack_node *b);
void					find_middle_and_split(t_stack_node *source,
							t_stack_node **front_ref, t_stack_node **back_ref);
void					merge_sort(t_stack_node **head_ref);

// operations
void					push_node(t_stack_list *stack, int value);
int						pop_node(t_stack_list *stack);
void					pb(t_stack_list *stack_a, t_stack_list *stack_b);
void					pa(t_stack_list *stack_a, t_stack_list *stack_b);
void					reverse_rotate(t_stack_list *stack);
void					rra(t_stack_list *stack_a);
void					rrb(t_stack_list *stack_b);
void					rrr(t_stack_list *stack_a, t_stack_list *stack_b);
void					rotate(t_stack_list *stack);
void					ra(t_stack_list *stack_a);
void					rb(t_stack_list *stack_b);
void					rr(t_stack_list *stack_a, t_stack_list *stack_b);
void					swap(t_stack_list *stack);
void					sa(t_stack_list *stack_a);
void					sb(t_stack_list *stack_b);
void					ss(t_stack_list *stack_a, t_stack_list *stack_b);

// sort algorithms
void					sort_stack(t_stack_list *stack_a,
							t_stack_list *stack_b);
int						is_sorted(t_stack_list *stack);
void					sort_three(t_stack_list *stack);

// utils
long					ft_atol(char *str);
int						ft_isdigit(int c);