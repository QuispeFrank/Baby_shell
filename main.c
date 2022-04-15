#include "main.h"

void _execve(char **argVec)
{
	pid_t pid = 0;
	int status = 0;

	/* el programa se divide en padre e hijo */
	pid = fork();

	if (pid == -1)
	{
		exit(1);
	}
	else if (pid == 0)
	{
		/* child */
		execve(argVec[0], argVec, NULL);
		_free(argVec);
		free_env();
		exit(0);
	}
	else
	{
		/* father */
		wait(&status);
		_free(argVec);
	}	
}



int main(void)
{
	char *prompt = "$ ", *cmd = NULL, **av = NULL;

	environ = _copyenv();
	if (!environ)
		exit(-100);

	while(1)
	{
		/* muestra el prompt */
		write(STDOUT_FILENO, prompt, 2);
		cmd = promp();

		cmd = spaces(cmd);

		if (_strcmp(cmd, "exit") == 0)
		{

			if(cmd)
			{
				free(cmd);
				free_env();
			}
			exit(0);
		}

		av = tokenizer(cmd, " ");
		/*Si no es un Script, ni un builting, verificamos el tipo de env*/
		/*Se verifica si es de tipo /bin/ls o ls */

		valid_exec(av);
				/*Antes de enviarse a ejecutar, se deberi validarse si existe o no el path*/
		free(cmd);
		//if (av != NULL)
//			_execve(av);// Lo he colocado en validation_execution.c 
		//else
			//	_free(av);
	}
	return (0);
}
