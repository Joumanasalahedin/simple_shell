#include "shell.h"

/**
 * command_args - tokenize command to arguments
 * @command: to be tokenized
 *
 * Return: command string.
 */

int command_args(char *command)
{
	char **args;
	int status = -1;

	args = shell_split_line(command);

	if (args == NULL)
	{
		printf("Error: %s\n", command);
		return (-1);
	}

	status = execute(args);

	free(args);

	if (status == -1)
	{
		printf("Error: %s\n", command);
	}

	return (status);
}
