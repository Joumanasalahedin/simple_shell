#include "shell.h"

/**
 * shell_read_line - reads and allocate string with line to read in stdin
 *
 * Return: pointer to a string with line to content.
 */

char *shell_read_line(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	int status = -1;

	printf("$ ");
	characters = getline(&command, &bufsize, stdin);

	if (characters == -1)
	{
		free(command);
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	if (command[characters - 1] == '\n')
	{
		command[characters - 1] = '\0';
	}

	status = execute(command);
	if (status == -1)
	{
		printf("Error, %s\n", command);
	}

	return (command);
}
