#include "shell.h"

/**
  * s_ignore - ignores spaces and newlines
  * @str: string
  * Return: new string
  */

char *s_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
	{
		str++;
	}
	return (str);
}

/**
  * non_interactive - handles non interactive shell
  * @env: env variables
  */

void non_interactive(list_t *env)
{
	size_t i = 0, n = 0;
	int line_no = 0, exit_stat = 0;
	char *command = NULL, *new = NULL, **com_lines, **toks;

	i = _getline(&command);

	if (i == 0)
	{
		free(command);
		exit(0);
	}
	new = command;
	command = s_ignore(command);
	com_lines = _strtok(command, "\n");

	if (new != NULL)
		free(new);

	n = 0;
	while (com_lines[n] != NULL)
	{
		line_no++;
		toks = NULL;
		toks = _strtok(com_lines[n], " ");
		exit_stat = builtin_c(toks, env, line_no, NULL);
		if (exit_stat)
		{
			n++;
			continue;
		}

		exit_stat = execute(toks, env, line_no);
		n++;
	}
	sh_free_double_ptr(com_lines);
	free_linked(env);
	exit(exit_stat);
}
