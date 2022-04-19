#include "main.h"

/**
 * already_exist_then_replace - verifica si existe una variable de entorno.
 * @av: double pointer who contain the name to find.
 *
 * Description: la funcion verifica @av contenga un nombre valido que se 
 * encuentre dentro del double pointer environ, si encuentra reemplaza 
 * su valor(usa malloc) y libera la memoria del antiguo valor, si falla
 * devuelve -2, si no encuentra la variable de entorno devuelve -1.
 *
 * Return: -2 if it fails, -1 if the variable env doesnt exist, 0 in success.
 */
int already_exist_then_replace(char **av)
{
	char *env_aux = NULL;
	int r_index = 0;

	r_index = _getenv_index(av[1]);
	if (r_index != -1)
	{
		/* existe, guardamos contenido original por si falla algo */
		env_aux = environ[r_index];
		/* reemplazo del antiguo bloque */ 
		environ[r_index] = _getenv_format(av);
		if (environ[r_index] == NULL)
		{
			environ[r_index] = env_aux;
			return(-2);
		}
		free(env_aux);
		reinit_environ(_dupdou_pointer_from(environ));
		return(0);
	}
	return (-1);
}


/**
 * douptr_cpy - function that copy a double pointer.
 * @src: a double pointer where from stare copying.
 * @dest: double pointer where to store the copy.
 *
 * Description: esta funcion hace una copia desde el double 
 * pointer @src hacia el double pointer @dest, para lograrlo
 * el puntero destino debe contener el espacio necesario o mas,
 * esta funcion hace uso de malloc, si la copia falla libera
 * el double puntero @dest.
 *
 * Return: NULL si falla, otherwise @dest.
 */
char **douptr_cpy(char **dest, char **src)
{
	int index = 0;
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

	return(dest);
}

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
	int len;

	/* tamaño del source */
        for (len = 0; src[len]; len++)
		;

	/* espacio para los punteros */
        dest = malloc(sizeof(char *) * (len + 1));
        if (dest == NULL)
                return (NULL);

	/* se duplica desde src hacia dest */
	dest = douptr_cpy(dest, src);
	if (dest == NULL)
		return (NULL);

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
