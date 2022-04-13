#include "main.h"

int cuenta_letras(char *str, char *delim)
{
	int letras = 0;
	/* mientras letras no encuentran el nulo o el delimitador */
	while (str[letras] && str[letras] != delim[0])
		letras++;

	return (letras);
}

int cuenta_los_tokens(char *str, char *delim)
{
	int size_str = 0, tokens = 0, i;

	/* tamaño total del string */
	for (size_str = 0; str[size_str]; size_str++)
		;
	for (i = 0; i < size_str; i++)
	{
		if (str[i] != delim[0])
		{
			tokens += 1;
			i += cuenta_letras(&str[i], delim);
		}
	}
	return (tokens);
}

char **strtok_emulator(char *str, char *delim)
{
	char **ptr = NULL;
	int tokens = 0, token = 0, letras = 0, letra = 0, i = 0;

	/* contamos el numero de tokens en str */
	tokens = cuenta_los_tokens(str, delim);
	if (tokens == 0)
		return (NULL);

	/* levantamos ptr */
	ptr = malloc(sizeof(char *) * (tokens + 1));
	if (ptr == NULL)
		return (NULL);

	/* copiamos los tokens en ptr */
	for (token = 0; token < tokens; token++)
	{
		while (str[i] == delim[0])
			i++;
		letras = cuenta_letras(&str[i], delim);

		/* malloc para un token */
		ptr[token] = malloc(sizeof(char) * (letras + 1));
		if (ptr[token] == NULL)
		{
			for (i -= 1; i >= 0; i--)
				free(ptr[i]);
			free(ptr);
			return (NULL);
		}
		/* copiando un token */
		for (letra = 0; letra < letras; letra++)
		{
			ptr[token][letra] = str[i];
			i++;
		}
		ptr[token][letra] = '\0';
	}
	ptr[token] = NULL;
	
	return (ptr);
}

