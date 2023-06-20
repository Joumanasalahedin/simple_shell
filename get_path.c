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
	char *path_dup;
	char *cmd_path;

	if (!path)
	{
		path_dup = _strdup(path);
		direct = strtok(path_dup, ":");

		while (direct != NULL)
		{
			cmd_path = malloc(_strlen(direct) + _strlen(command) + 2);
			if (cmd_path == NULL)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			strcpy(cmd_path, direct);
			strcat(cmd_path, "/");
			strcat(cmd_path, command);

			if (access(cmd_path, X_OK) == 0)
			{
				free(path_dup);
				return (cmd_path);
			}
			free(cmd_path);
			direct = strtok(NULL, ":");
		}
		free(path_dup);

		if (access(command, X_OK) == 0)
		{
			return (strdup(command));
		}
	}
	return (NULL);
}
