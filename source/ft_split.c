#include "push_swap.h"

int count_words(char *str, char c)
{
	int i;
	int count;

	if (!str)
		return (0);

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

int word_len(char *str, char c)
{
	int len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

void *free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (NULL);
}

char **ft_split(char *s, char c)
{
	char **array;
	int array_index;
	int word_count;
	int len;

	array_index = 0;
	word_count = count_words(s, c);
	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	while ((array && array_index < word_count))
	{
		while (*s && *s == c)
			s++;
		array[array_index] = (char *)malloc(sizeof(char) * (word_len(s, c) + 1));
		if (!array[array_index])
			return (free_array(array));
		len = 0;
		while (*s && *s != c)
			array[array_index][len++] = *s++;
		array[array_index++][len] = '\0';
	}
	if (array)
		array[array_index] = NULL;
	return (array);
}