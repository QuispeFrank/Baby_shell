#include "main.h"

/**
 * valid_exec - function that validates
 * @av: array eoth values to evaluate
 * @valid_built_env: and int variable
 * Return: nothin
 */

void valid_exec(char **av)
{
        char **argv;

		printf("new\n");
        argv = validation(av);
        if (argv == NULL)
        {
             perror(av[0]);
             return;
         }
        else
		{	
			_execve(argv);
			free(argv);
		}
}
