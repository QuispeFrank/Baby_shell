#include "main.h"

/**
 * validation - function that validates
 * and built or env
 * @arv: array eoth values to evaluate
 * Return: char **
 */
char **validation(char **arv)
{
	char *fc, *sc, **new_arv = NULL;
	int count;
	char *c[] =  {".", "/"};

	fc = arv[0];
	sc = fc + 1;
	while (arv[count])
		count++;
	if ((fc[0] == *c[0] && sc[0] == *c[1]) || (fc[0] == *c[1]))
	{
		arv[count] = NULL;
		return(arv);
	}
    else
    {
		new_arv = arv_for_execute(arv);
		return (new_arv);
	}
}
