#include "shell.h"

/**
 * get_path - extracts a value from semi-structured
 * data using a path name.
 * @command: arguments
 *
 * Return: NULL
 */

char *get_path(char *command)
{
	char *path = getenv("PATH");
	char *direct;
	char *cmd_path;

	if (access(command, X_OK) == 0)
	{
		return (_strdup(command));
	}

	if (!path)
	{
		return (NULL);
	}

	direct = strtok(path, ":");

	while (direct != NULL)
	{
		cmd_path = malloc(_strlen(direct) + _strlen(command) + 2);
		if (cmd_path == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		_strcpy(cmd_path, direct);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, command);

		if (access(cmd_path, X_OK) == 0)
		{
			return (cmd_path);
		}
		free(cmd_path);
		direct = strtok(NULL, ":");
	}

	return (NULL);
}
