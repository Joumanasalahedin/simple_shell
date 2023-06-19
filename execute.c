#include "shell.h"

/**
  * execute - executes a command
  * @command: command argument
  * Return: 1 (Success)
  */

int execute(char **args)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("./hsh");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execv(args[0], args) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("./hsh");
			return (-1);
		}
	}

	return (0);
}
