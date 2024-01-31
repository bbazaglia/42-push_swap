#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* difference between current_pos, target_pos and index:

** current_pos: current position of a node within its respective stack

** index: the final desired position for the node in the sorted stack_a

** target_pos: the position in stack A where an element from stack B should be placed
- base case: the position of the element with the closest smaller index in stack A is the target position for the element in stack B.
- special case: if an element in stack B has a higher index than all elements in stack A, 
its target position is the position of the element with the smallest index in stack A.
*/

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					target_pos;
	int					index;
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
	int 				length;
}						t_stack_list;

// check functions
char					**check_input(int argc, char **argv);
void					check_characters(char *argv);
void					check_limit(char *argv);
void					check_double(t_stack_list *stack);
void					print_error(void);

// split functions 
int						count_words(char *str, char c);
int						word_len(char *str, char c);
void					*free_array(char **array);
char					**ft_split(char *s, char c);

// linked list functions
t_stack_list			*create_stack(int argc, char **argv);
void					add_node(t_stack_list *stack, int value);
void					clear_stack(t_stack_list *stack);
int						stack_length(t_stack_list *stack);
void					copy_stack(t_stack_list *src, t_stack_list *dest);
void 					print_stack(t_stack_list *stack);

// assign positions (index, current_pos and target_pos)
void 					get_positions(t_stack_list *stack_a, t_stack_list *stack_b);
void					get_cur_pos(t_stack_list *stack);
int						get_target_pos(t_stack_list *stack, int index_b, int max_index, int target);
int						get_lowest_index_pos(t_stack_list *stack);
void					assign_index(t_stack_list *stack);
t_stack_node			*merge_sorted_lists(t_stack_node *a, t_stack_node *b);
void					find_middle_and_split(t_stack_node *source, t_stack_node **front_ref, t_stack_node **back_ref);
void					merge_sort(t_stack_node **head_ref);

// operations
void 					push(t_stack_list *src, t_stack_list *dest);
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

// sorting algorithm
void					sort_stack(t_stack_list *stack_a, t_stack_list *stack_b);
int						is_sorted(t_stack_list *stack);
void					sort_three(t_stack_list *stack);
void					sort_bigger(t_stack_list *stack_a, t_stack_list *stack_b);
void 					populate_stack_b(t_stack_list *stack_a, t_stack_list *stack_b);
void 					adjust_stack_a(t_stack_list *stack_a);
void					get_cost(t_stack_list *stack_a, t_stack_list *stack_b);
void					do_cheapest_move(t_stack_list *stack_a, t_stack_list *stack_b);
void					do_move(t_stack_list *stack_a, t_stack_list *stack_b, int cheapest_cost_a, int cheapest_cost_b);

// utils
long					ft_atol(char *str);
int						ft_isdigit(int c);
int						ft_abs(int n);