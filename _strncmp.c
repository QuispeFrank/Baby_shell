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
