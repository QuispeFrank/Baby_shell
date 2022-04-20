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
	char **ptr = NULL; 
	int index = 0, len = 0, ok = 0;
	/* se deberia validar el numero de argumentos = 3 */
	/* existe el nuevo environ yet? */
	ok = already_exist_then_replace(av);
	if (ok == 0 || ok == -2)
		return (ok);

	/* contamos environ */
	for (len = 0; environ[len]; len++)
		index++;
	
	/* se asigna el espacio en ptr */
	ptr = malloc(sizeof(char *) * (len + 2));
	if (ptr == NULL)
		return(-1);

	/* se copia desde environ hacia ptr con malloc */
	ptr = douptr_cpy(ptr, environ);
	if (ptr == NULL)
		return (-1);
	
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


/**
 * _unsetenv - deletes a variable name from the environment.
 * @av: a double pointer that contains name.
 *
 * Description: The unsetenv() function deletes the variable 
 * name  from  the  environment. if name does not exist in the 
 * environment, then the function succeeds, and the environment 
 * is unchanged.
 *
 * Return: -1 on error, 0 in success.
 */
int _unsetenv(char **av)
{
	char **ptr;
	int index = 0, len = 0, exist = 0, bingo = 0, ok = 0;
/*  -----  */
	/* existe index? */
	exist = _getenv_index(av[1]);
	if (exist == -1)
		return (-1);
	
	/* index existe y se prepara espacio en ptr */
	/* se mide el tamaño de environ */
	while (environ[len])
		len++;

	ptr = malloc(sizeof(char *) * len);
	if (ptr == NULL)
		return (-1);
/*  ------  */
	/* comienza la copia desde env hacia ptr */
	/* sin la posicion index de env */
	while (index < len)
	{
		if (index == exist)
			bingo = 1;

		ptr[index] = _strdup(environ[index + bingo]);
		if (ptr[index] == NULL && (index != len - 1))
		{
			_free(ptr);
			return (-1);
		}
		index++;
	}
/*  -----  */
	/* environ se mueve con ptr */
	ok = reinit_environ(ptr);
	return (ok);
}
