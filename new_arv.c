#include "main.h"

char **arv_to_execute(char **arv1, char *total)
{
	int k = 1, count, i;
	char **new_arv = NULL;
	
	while (arv1[count])
	{
		count++;
	}
	new_arv = malloc(sizeof(char *) * (count + 1));
	for (i = 0; i <= count; i++)
	{
		new_arv[i] = malloc(sizeof(char) * 20);
	}

	new_arv[0] = total;
	while(k < count)
	{
		strcpy(new_arv[k], arv1[k]);
		k++;
	}
	new_arv[k] = NULL;
	return (new_arv);
}
