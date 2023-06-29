#include "shell.h"

/**
 * builtin_c - match and execuute builtin
 * @toks: typed command
 * @env: variables
 * @n: error massage
 * @command: cmd to free
 *
 * Return: 1 or 0
 */

int builtin_c(char **toks, list_t *env, int n)
{
	if (toks == NULL || toks[0] == NULL)
		return (0);
	if (_strcmp(toks[0], "exit") == 0)
	{
		sh_exit(toks, NULL, env, n);
		return (1);
	}
	else if (_strcmp(toks[0], "env") == 0)
	{
		print_env(toks, env);
		return (1);
	}
	else if (_strcmp(toks[0], "unsetenv") == 0)
	{
		sh_unsetenv(&env, toks);
		return (1);
	}
	else if (_strcmp(toks[0], "setenv") == 0)
	{
		sh_setenv(&env, toks);
		return (1);
	}
	return (0);
}
