#include "main.h"

/**
 * *_strcat - Function that concatenates two strings.
 * This function appends the src string to the dest string,
 * overwriting the terminating null byte (\0) at the end of dest,
 * and then adds a terminating null byte.
 *
 * @dest: A pointer to the string to be concatenated upon.
 * @src: The source string to be appended to @dest.
 *
 * Return: A pointer to the destination string @dest.
 */

char *_strcat(char *dest, const char *src)
{

	int n_elem_src = 0, n_elem_dest = 0;
	int j;

	/*counting arrays*/
	while (src[n_elem_src] != '\0')
	{
		n_elem_src += 1;
	}

	while (dest[n_elem_dest] != '\0')
	{
		n_elem_dest += 1;
	}

	/*printing it*/
	for (j = 0; j <= n_elem_src; j++)
	{
		dest[n_elem_dest + j] = src[j];
	}

	return (dest);
}


/**
 * *_strncat - function that concatenates two strings.
 * The _strncat function is similar to the _strcat function, except that
 * it will use at most n bytes from src
 * src does not need to be null-terminated if it contains n or more bytes.
 *
 * @dest: A pointer to the string to be concatenated upon.
 * @src: The source string to be appended to @dest.
 * @n: number of elements to be concatenated.
 *
 * Return: A pointer to the resulting string @dest.
 */

char *_strncat(char *dest, const char *src, size_t n)
{

	size_t n_elem_src = 0, n_elem_dest = 0, j;

	/* counting arrays */
	while (src[n_elem_src] != '\0')
	{
		n_elem_src += 1;
	}

	while (dest[n_elem_dest] != '\0')
	{
		n_elem_dest += 1;
	}

	/* setting the limit to n elements */
	if (n < n_elem_src)
		n_elem_src = n;

	/*concatenating */
	for (j = 0; j < n_elem_src; j++)
	{
		dest[n_elem_dest + j] = src[j];
	}

	return (dest);
}


/**
 * _strchr - function that locates a character in a string.
 *
 * @s: A pointer to array of chars where to find the char
 * @c: char to find
 * Return: @dest
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;
	unsigned int fin = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			break;
		i++;
		if (s[i + 1] == '\0')
			fin = 1;
	}
	if (c != '\0' && fin == 1)
		return (NULL);
	return (s + i);
}


/**
 * _strlen -  function that returns the length of a string
 * @s: ..
 * Return: returns the length of a string
 */

int _strlen(const char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}

	return (i);
}


/**
 * _strcmp - function that concatenates two strings.
 * The _strncat function is similar to the _strcat function, except that
 * it will use at most n bytes from src
 * src does not need to be null-terminated if it contains n or more bytes.
 *
 * @s1: A pointer to the first string to be compared with @s2
 * @s2: A pointer to the second string
 *
 *
 * Return: return 0 if s1 = s2.
 */


int _strcmp(char *s1, char *s2)
{
	int c = 0, i = 0;

	while (s1[i] != '\0')
	{
		c = s1[i] - s2[i];
		i += 1;
		if (c != 0)
			break;
	}
	return (c);
}
