#include "main.h"

int main(void)
{
	dir_t *head = NULL;
	char *cmd = "setenv HELLO BABY";
	char *cmd2 = "setenv PATH /bin/bruno";
	char *cmd3 = "unsetenv HELLO";
	char *cmd4 = "unsetenv SHLVL";
	char **av = NULL;
	int index = 0;

	/* agregando mi nuevo environ */
	copy_env();

	/* deberiamos usar setenv despues de validar
	 * casos raros y luego del strtok se asume eso */

	/* agrega HELLO */
	av = tokenizer(cmd2, " ");
	_setenv(av);
	_free(av);

	/* reemplaza PATH */
	av = tokenizer(cmd, " ");
	_setenv(av);
	_free(av);

	/* imprime environ */
	for (index = 0; environ[index]; index++)
		printf("%s\n", environ[index]);

	/* elimina una variable de entorno */
	av = tokenizer(cmd3, " ");
	_unsetenv(av);
	_free(av);

	av = tokenizer(cmd4, " ");
	_unsetenv(av);
	_free(av);

	/* imprime environ */
	for (index = 0; environ[index]; index++)
		printf("%s\n", environ[index]);

	/* se cambia los malloc por los linked list */
	 head = _linked_path(PATH);

	/* imprimimos los paths desde el linked list */
	 print_list(head);

	/* liberamos el linked_list */
	 free_list(head);
	 free_env();
	/* valgrind ok :) */
	 return (0);
}
