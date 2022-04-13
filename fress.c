#include "main.h"

/**
 * _free - frees double pointer
 * @av: input double pointer
 *
 * Return: void
 */

void _free(char **av)
{
	int i = 0;

	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
