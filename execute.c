#include "shell.h"

/**
  * execute - executes a command
  * @command: command argument
  * Return: 1 (Success)
  */

int execute(char *command)
{
	pid_t pid = fork();
	char *args[2];
	int status;

	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	else if (pid == 0)
	{
		args[0] = command;
		args[1] = NULL;

		if (execv(command, args) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			return (-1);
		}
	}

	return (0);
}
