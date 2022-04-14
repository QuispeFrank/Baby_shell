#include "main.h"

/**
 * _strspn - function that gets the length of a prefix substring.
 *
 * @s: A pointer to array of chars where to find the chars
 * @accept: array of chars from it gets the char
 *
 * Return: the number of bytes in the initial segment of s which
 * consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int catch, counter = 0;
	int i = 0, j = 0;

	while (s[i] != '\0')
	{
		catch = 0;
		j = 0;

		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				counter += 1;
				catch = 1;
				i += 1;
				break;
			}
			j += 1;
		}
		if (catch == 0)
			break;
	}
	return (counter);
}


/**
 * *_strcpy - copies the string pointed to by src, including the
 * terminating null byte (\0), to the buffer pointed to by dest.
 *
 * @dest: write your text copied
 * @src: where from copy
 *
 * Return: pointer dest
 */

char *_strcpy(char *dest, const char *src)
{
	int index = 0;

	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index += 1;
	}
	dest[index] = '\0';
	return (dest);
}


#include "main.h"
/**
 * _strncmp - Compare two strings.
 * @s1: Pointer to a string.
 * @s2: Pointer to a string.
 * @n: The first n bytes of the strings to compare.
 *
 * Return: Less than 0 if s1 is shorter than s2.
 *         0 if s1 and s2 match.
 *         Greater than 0 if s1 is longer than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
        size_t i;

        for (i = 0; s1[i] && s2[i] && i < n; i++)
        {
                if (s1[i] > s2[i])
                        return (s1[i] - s2[i]);
                else if (s1[i] < s2[i])
                        return (s1[i] - s2[i]);
        }
        if (i == n)
                return (0);
        else
                return (-15);
}
