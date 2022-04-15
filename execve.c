#include "main.h"

/**
 * _execve - execute commands
 * @argVec: argument vecto of input
 *
 * Return: void
 */

void _execve(char **argVec)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: ");
		exit(0);
	}
	else if (child_pid == 0)
	{
		if (execve(argVec[0], argVec, environ) == -1)
		{
			perror(argVec[0]);
			exit(0);
		}
		/*SIGKILl: para terminar el proceso*/
		kill(child_pid, SIGKILL);
	}
	else if (child_pid > 0)
	{
		wait(&status);
	}
}
