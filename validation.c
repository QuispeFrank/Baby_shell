#include "main.h"

/**
 * validation - function that validates
 * and built or env
 * @arv: array eoth values to evaluate
 * Return: char **
 */
char **validation(char **arv)
{
	char *fc = NULL, *sc = NULL, **new_arv = NULL;
	int count = 0, val = 0;
	char *c[] =  {".", "/"};

	fc = arv[0];
	sc = fc + 1;
	while (arv[count])
		count++;
	if ((fc[0] == *c[0] && sc[0] == *c[1]))
	{
		new_arv = malloc(sizeof(char *) * 2);	
		new_arv[0] = arv[0];
		new_arv[1] = NULL;
		return(new_arv);
	}
	else if (fc[0] == *c[1])
	{
		val = access(arv[0], X_OK);
		if(val == 0)
		{
			new_arv = arv_to_execute(arv, arv[0]);
			return (new_arv);
		}
		return (NULL);
	}
    else
	{
		new_arv = arv_for_execute(arv);
		return (new_arv);
	}
}
