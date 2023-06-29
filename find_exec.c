#include "shell.h"

/**
  * find_exec - fleshes command
  * @command: user's command
  * @env: environmental variable
  * Return: copy of command
  */

char *find_exec(char *command, list_t *env)
{
	char *path, *cat = NULL, **tokens;
	int i = 0;

	path = h_getenv("PATH", env);
	tokens = token_string(path, ":");
	free(path);

	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] == '\0')
			cat = getcwd(cat, 0);
		
		else
			cat = _strdup(tokens[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, command);
		
		if (access(cat, F_OK) == 0)
		{
			sh_free_double_ptr(tokens);
			return (cat);
		}
		
		free(cat);
		i++;
	}
	sh_free_double_ptr(tokens);
	return (command);
}
