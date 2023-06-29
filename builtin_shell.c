#include "shell.h"

/**
 * exit_c - user type command
 * @s: typed cmd
 * @env: variable
 */
void exit_c(char **s, list_t *env)
{
	sh_free_double_ptr(s);
	free_linked(env);
	_exit(0);
}

/**
 * sh_env - prints the current environment
 * @args: arguments
 *
 * Return: 0 success
 */

int sh_env(char **args)
{
	char **env = environ;
	int j = 0;
	(void)(**args);

	while (env[j])
	{
		write(STDOUT_FILENO, env[j], strlen(env[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
	return (0);
}

/**
 * sh_help - print help
 * @args: arguments
 *
 * Return: 1 for success 0 failure
 */

int sh_help(char **args)
{
	(void)(**args);

	printf("\n---help hsh---\n");
	printf("command and arguments, enter\n");
	printf("Built-in commands:\n");
	printf(" -> sh_cd\n");
	printf(" -> sh_env\n");
	printf(" -> sh_exit\n");
	printf(" -> sh_help\n");
	printf("man command for information. \n\n");

	return (1);
}

