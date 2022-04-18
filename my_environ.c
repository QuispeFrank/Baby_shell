#include "main.h"

/**
 *
 *
 */


/**
 * _dupdou_pointer_from - a function that duplicates a double pointer.
 * @src: source from copy.
 *
 * Description: this funcion takes a double pointer @src and duplicates it, using
 * malloc(3).
 *
 * Return: NULL if it fails, otherwise @dest.
 */
char **_dupdou_pointer_from(char **src)
{
	char **dest = NULL;
	int len, index = 0;

	/* tamaño del source */
        for (len = 0; src[len]; len++)
                ;

	/* espacio para los punteros */
        dest = malloc(sizeof(char *) * (len + 1));
        if (dest == NULL)
                return (NULL);

	/* comienza la copia desde src hacia dest */
	while (src[index])
        {
		/* duplicando una variable de entorno en ptr */ 
		dest[index] = _strdup(src[index]);
		if (dest[index] == NULL)
		{
			_free(dest);
			return(NULL);
		}
		index++;
	}
	dest[index] = NULL;

	return (dest);
}

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
 * _getenv - get and environment variable
 * @name: environment variable to get.
 *
 * Description: The getenv() function searches the environment
 * list to find the environment variable name, and returns a
 * pointer to the corresponding value string.
 *
 * Return: NULL si no encuentra, otherwise a pointer to variable 
 * environment.
 */
char *_getenv(const char *name)
{
	unsigned int index = 0, letter = 0;

	while (environ[index])
	{
		letter = 0;
		while (name[letter])
		{
			if (name[letter] == environ[index][letter])
			{
				letter++;
				if (!name[letter] && environ[index][letter] == '=')
					return (environ[index]);
				continue;
			}
			else
				break;
		}
		index++;
	}
	return (NULL);
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


/**
 * free_env - frees environ and PATH
 *
 * Return: void
 */

void free_env(void)
{
	_free(environ);
	_free(PATH);
}
