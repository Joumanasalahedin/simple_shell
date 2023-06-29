#include "shell.h"

/**
  * ctrl_c - ignore ctrl+c and print prompt
  * @n: int
  */

void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
  * ctrl_d - exits program
  * @c: characters read
  * @command: command types in shell
  * @env: variable
  */

void ctrl_d(int i, char *command, list_t *env)
{
	if (c == 0)
	{
		free(command);
		sh_free_linked_list(env);

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);

		exit(0);
	}
}

/**
  * ignore_spaces - removes spaces in string
  * @str: string
  * Return: string without spaces
  */

char *ignore_spaces(char *str)
{
	while (*str == ' ')
		str++;

	return (str);
}
