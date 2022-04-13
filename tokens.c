#include "main.h"

/**
 * tokenizer - - function that create tokens
 * @input: is a char pointer of a string
 * @delimt: is a char pointer delimitator
 *
 * Return: double pointer to strings
 */

char **tokenizer(char *input, char *delim)
{
	int count = 0;
	char **av = NULL;

	av = strtok_emulator(input, delim);

	return (av);
}
