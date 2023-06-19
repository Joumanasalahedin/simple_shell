#include "shell.h"

/**
 * command_args - tokenize command to arguments
 * @command: to be tokenized
 *
 * Return: command string.
 */

int command_args(char *command)
{
	char *args[BUFSIZE];
	int a = 0;
	int status = -1;
	char *tok;

	tok = strtok(command, " ");

	while (tok != NULL)
	{
		args[a++] = tok;
		tok = strtok(NULL, " ");
	}

	args[a] = NULL;

	status = execute(args[0]);

	if (status == -1)
	{
		printf("Error: %s\n", command);
	}

	return (status);
}
