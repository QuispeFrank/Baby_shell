#include "main.h"

/**
  * arv_for_execute - function that validates or execute
  * @arv: array eoth values to evaluate
  * Return: 0 char **
  */

char **arv_for_execute(char **arv)
{
	char *total = NULL, *PATH1 = NULL, **new_arv = NULL, **Path_tokens = NULL;
	int i = 0, val;

	PATH1 = getenv("PATH");
	
	Path_tokens = tokenizer(PATH1, ":");
	
	total = malloc(sizeof(char) * 100);
	if (total == NULL)
		return (0);
	
	while (Path_tokens[i])
	{
		total = strcpy(total, Path_tokens[i]);
		total = strcat(total, "/");
		total = strcat(total, arv[0]);
		val =  access(total, X_OK);
		if (val == 0)
		{
			new_arv = arv_to_execute(arv, total); 
			return (new_arv);
		}
		i++;
	}
	free(new_arv);
	free(total);
	return (NULL);
}


