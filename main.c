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
	ssize_t bytes_read = 0;
	size_t n = 0;
	char *prompt = "$ ", *cmd = NULL, **av = NULL;

	environ = _copyenv();
	if (!environ)
		exit(-100);

	while(1)
	{
		/* muestra el prompt */
		write(STDOUT_FILENO, prompt, 2);

		cmd = NULL;
		/* lectura a traves del getline */
		bytes_read = getline(&cmd, &n, stdin);

		/* validaciones */
		if (bytes_read == -1)
		{
			if(cmd)
			{
				free(cmd);
				free_env();
			}
			exit(0);
		}
		
		cmd[_strlen(cmd) - 1] = '\0';

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
		free(cmd);

		_execve(av); 
	}
	return (0);
}
