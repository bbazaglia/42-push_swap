#include "push_swap.h"

t_stack	*initialize_stack(int argc, char **argv)
{
	t_stack	*head;
	t_stack	*tail;
	int		i;
	int		value;
	t_stack	*new_node;

	head = NULL;
	tail = NULL;
	i = 1;
	while (i < argc)
	{
		value = atoi(argv[i]);
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->value = value;
		new_node->next = NULL;
		new_node->prev = tail;
		if (tail)
			tail->next = new_node;
		tail = new_node;
		if (!head)
			head = new_node;
		i++;
	}
	return (head);
}


