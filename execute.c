#include "shell.h"

/**
  * execute - executes a command
  * @args: arguments
  * Return: 1 (Success)
  */

int execute(char **args)
{
	pid_t pid = fork();
	int status;
	char *path;

	if (pid == -1)
	{
		perror("./hsh");
		return (-1);
	}
	else if (pid == 0)
	{
		path = get_path(args[0]);

		if (path == NULL)
		{
			printf("Command not found: %s\n", args[0]);
			exit(EXIT_FAILURE);
		}

		if (execv(path, args) == -1)
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
