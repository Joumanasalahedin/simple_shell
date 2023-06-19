#include "shell.h"

/**
 * shell_split_line - split string into seperate arguments
 * @command: string to be split
 *
 * Return: new array.
 */

char **shell_split_line(char *command)
{
	int p = 0;
	int bufsize = 64;
	char *tok;
	char **toks = malloc(bufsize * sizeof(char *));

	if (!toks)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	tok = strtok(command, " \t\n");

	while (tok != NULL)
	{

		toks[p] = _strdup(tok);
		p++;
		if (p >= bufsize)
		{
			bufsize += 64;
			toks = realloc(toks, bufsize * sizeof(char *));

			if (!toks)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		tok = strtok(NULL, " \t\n");
	}

	toks[p] = NULL;
	return (toks);
}
