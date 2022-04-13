#include "main.h"

char *spaces(char *input)
{	
	int i = 0, j = 0;
	char *result = NULL;

	result = malloc(sizeof(char) * _strlen(input));
	if (result == NULL)
		return(NULL);

	for (i = 0; (input[i] == 32) || (input[i] == 9); i++)
                        ;
	
	for (j = 0; input[i] != '\0'; i++, j++) /* entra algo más al input*/
		result[j] = input[i];
	result[j] = '\0';
	free(input);
	return (result);
}
