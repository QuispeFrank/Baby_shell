#include "main.h"

/**
 * copy_env - initial function that init the environ.
 *
 * Description: this function makes a copy from environ
 * and kept it in a double pointer called environ. it
 * should be used when main function starts.
 */
void copy_env(void)
{
	/* environ se muda a una copia */ 
	environ = _dupdou_pointer_from(environ);
	if (environ == NULL)
		exit(0);

	/* como todo esta Okey obtenemos $PATH */
	PATH = _paths(_getenv("PATH"));
	if (PATH == NULL)
	{
		_free(environ);
		exit (0);
	}
}


/**
 * _paths - funcion que obtiene los directorios en $PATH.
 * @nombre: puntero de la variable de entorno $PATH.
 *
 * Return: un doble puntero que contiene los directorios 
 * de PATH.
 */
char **_paths(char *nombre)
{
	char *valor = NULL, **paths = NULL;

	/* ubicacion del puntero valor a partir de '=' */
	valor = _strchr(nombre, '=');
	if (valor == NULL)
		return (NULL);

	/* almacenamos los paths en el doble puntero paths */
	paths = strtok_emulator(valor + 1, ":");
	if (paths == NULL)
		return(NULL);

	return(paths);
}


/**
 * linked_path - linked list de los directorios de $PATH.
 * @paths - a double pointer hacia los directorios.
 * 
 * Description: funcion que almacena los directorios
 * contenidos en la variable de entorno $PATH en una
 * single linked list.
 *
 * Return: head of the single linked list.
 */
dir_t *_linked_path(char **paths)
{
	dir_t *head = NULL;
	unsigned int index = 0;

	while (paths[index])
	{
		add_node_end(&head, paths[index]);
		index++;
	}
	return (head);
}
