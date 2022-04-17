#include "main.h"

/**
 * prompt - reads the command line
 *
 * Return: the command line as a string
 */

char *promp(void)
{
	char *input = NULL;
	size_t buf_size = 0;
	ssize_t bytes_read = 0;

	bytes_read = getline(&input, &buf_size, stdin);
	if (bytes_read == -1)
	{
		if (input)
		{
			free_env();
			free(input);
		}
		exit (0);
	}
	if (input == NULL)
	{
		free_env();
		exit(0);
	}
	input[_strlen(input) - 1] = '\0';
	return (input);
}
