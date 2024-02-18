#include "push_swap.h"

void free_args(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}