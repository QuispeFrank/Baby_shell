#include "main.h"

/**
 * get_env_format - funcion que devuelve un string en formato name=value.
 * @av: doble puntero que contiene name, value.
 *
 * Description: la funcion concatena 3 string: av[1], =, av[2] el cual
 * almacena en un puntero ptr con malloc.
 *
 * Return: NULL si falla, @ptr in success.
 */
char *_getenv_format(char **av)
{
	char *ptr = NULL;
	int len = 0, index = 0;

	/* calculo del espacio necesario para almacenar los 2 strings */
	for (index = 1; index < 3; index++)
		len = len + _strlen(av[index]);

	/* creando el espacio */
	ptr = malloc(sizeof(char) * (len + 2));
	if (ptr == NULL)
		return (NULL);

	/* almacenamiento en ptr */
	_strcpy(ptr, av[1]);
	_strcat(ptr, "=");
	_strcat(ptr, av[2]);

	return (ptr);
}

/**
 * _setenv - a function that change or add  an environment variable.
 * @av: a double pointer that contains name, value arguments.
 *
 * Return: -1 if fails adding, -2 if fails to overwrite, 0 in success.
 */
int _setenv(char **av)
{
	char **ptr = NULL, *env_aux = NULL; 
	int index = 0, len = 0, ok = 0, r_index = 0;

	/* se deberia validar el numero de argumentos = 3 */
	/* ptr debe tener un espacio adicional que environ */

	/* existe el nuevo environ yet? */
	r_index = _getenv_index(av[1]);
	if(r_index != -1)
	{
		/* existe, guardamos contenido original por si falla algo */
		env_aux = environ[r_index];
		/* existe, liberamos oldvalue */		
		environ[r_index] = _getenv_format(av);
		if (environ[r_index] == NULL)
		{
			environ[r_index] = env_aux;
			return(-2);
		}	
		free(env_aux);
		return(0);
	}
	
	/* contamos environ */
	for (len = 0; environ[len]; len++)
		;
	
	/* se asigna el espacio en ptr */
	ptr = malloc(sizeof(char *) * (len + 2));
	if (ptr == NULL)
		return(-1);

	/* comienza la copia desde environ hacia ptr */
        while (environ[index])
        {
                /* duplicando una variable de entorno en ptr */
                ptr[index] = _strdup(environ[index]);
                if (ptr[index] == NULL)
                {
                        _free(ptr);
                        return(-1);
                }
                index++;
        }
	/* se agrega la nueva variable de entorno */
        ptr[index] = _getenv_format(av);
	if (ptr[index] == NULL)
	{
		_free(ptr);
		return (-1);
	}
	ptr[index + 1] = NULL;
	/* reinicio del environment */
	ok = reinit_environ(ptr);

	return (ok);
}

/**
 * reinit_environ - funcion que reinicializa el environment.
 * @ptr: doble puntero que contiene el nuevo environment.
 *
 * Description: funcion que elige un doble puntero @ptr como base y
 * se lo entrega a la variable environ, reinicia $PATH, y libera los 
 * anteriores valores de environ y PATH.
 *
 * Return: -1 si falla, 0 en success.
 */
int reinit_environ(char **ptr)
{
	char **aux_env = NULL, **aux_path = NULL;

	/* guardamos environ y path en caso de fallo */
	aux_env = environ;
	aux_path = PATH;

	/* environ se muda con ptr */
	environ = ptr;

	/* reasignacion de $PATH */
	PATH = _paths(_getenv("PATH"));
	if (PATH == NULL)
	{
		environ = aux_env;
		PATH = aux_path;
		_free(ptr);
		return (-1);
	}
	/* como todo esta okey se libera aux_env y aux_path */
	_free(aux_env);
	_free(aux_path);

	return (0);
}

/**
 * _getenv_index - a function that find a name inside environ. 
 * @name: puntero al nombre a buscar.
 *
 * Description: this function busca si existe una variable de entorno
 * con el nombre apuntado por @name dentro de environ.
 *
 * Return: -1 si no encuentra la variable de entorno, otherwise
 * el indice donde se encuentra.
 */
int _getenv_index(char *name)
{
	int index = 0, letter = 0;

	/* estara name dentro de environ? */
        while (environ[index])
        {
                letter = 0;
                while (name[letter])
                {
                        if (name[letter] == environ[index][letter])
                        {
                                letter++;
                                if (!name[letter] && environ[index][letter] == '=')
                                        return (index);
                                continue;
                        }
                        else
                                break;
                }
                index++;
        }
        return (-1);
}


int main(void)
{
	/* char *ptr = "PATH"; */
	/* char *env_var = NULL; */
	/* char **paths = NULL; */
	dir_t *head = NULL;
	char *cmd = "setenv HELLO BABY";
	char *cmd2 = "setenv SHELL /bin/bruno";
	char **av = NULL;
	int index = 0;

	/* agregando mi nuevo environ */
	copy_env();

	/* deberiamos usar setenv despues de validar
	 * casos raros y luego del strtok se asume eso */
	av = tokenizer(cmd, " ");
	_setenv(av);
	_free(av);

	for (index = 0; environ[index]; index++)
		printf("%s\n", environ[index]);

	av = tokenizer(cmd2, " ");
	_setenv(av);

	/* env_var = _getenv(ptr); */
	/*
	if (!env_var)
	{
		printf("ruta no encontrada\n");
		free_env();
		return (0);
	}
	*/

	/* funcion que me obtiene los paths de $PATH y almacena en malloc */
	/* paths = _paths(env_var); */
	/*
	if (paths == NULL)
	{
		printf("algo fallo en _paths = NULL");
		free_env();
		return (0);
	}
	*/
	/* se cambia los malloc por los linked list */
	 head = _linked_path(PATH);
	/* se elimina el malloc anterior */
	/* _free(paths); */

	/* imprimimos los paths desde el linked list */
	 print_list(head);

	 /* impresion de environment */
	 for (index = 0; environ[index]; index++)
		 printf("%s\n", environ[index]);

	/* liberamos el linked_list */
	 free_list(head);
	 free_env();
	 _free(av);
	/* valgrind ok :) */
	 return (0);
}
