#include "shell.h"

/**
 * separator - separates commands
 * @str: string
 * Return: strings parsed
 */

char **separator(char *str)
{
	char **cmds = NULL;
	char *token = NULL;
	int j;
	int buffs = BUFSIZ;

	if (str[0] == ' ' && str[_strlen(str)] == ' ')
		exit(0);
	if (str == NULL)
		return (NULL);
	cmds = malloc(sizeof(char *) * buffs);

	if (!cmds)
	{
		free(cmds);
		perror("hsh");
		return (NULL);
	}
	token = strtok(str, ";&");
	for (j = 0; token; j++)
	{
		cmds[j] = _strdup(token);
		token = strtok(NULL, ";&");
	}
	cmds[j] = NULL;
	return (cmds);
}
