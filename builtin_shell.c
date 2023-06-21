#include "shell.h"

/**
 * sh_exit - exit the shell
 *
 * Return: 0 and exit shell
 */

int sh_exit(void)
{
	return (0);
}

/**
 * sh_cd - change directory
 * @args: arguments
 *
 * Return: 1 or 0.
 */

int sh_cd(char **args)
{
	if (args[1] == NULL)
	{
		printf("arguments to \"cd\"\n");
		return (1);
	}

	if (chdir(args[1]) != 0)
	{
		perror("chdir");
		return (1);
	}
	return (0);
}

/**
 * sh_env - prints the current environment
 * @args: arguments
 *
 * Return: 1 on success
 */

int sh_env(char **args)
{
	char **env = environ;
	(void)(**args);

	while (*env != NULL)

	{
		printf("%s\n", *env);
		env++;
	}
	return (1);
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
	printf(" -> cd\n");
	printf(" -> env\n");
	printf(" -> exit\n");
	printf(" -> help\n");
	printf("man command for information. \n\n");

	return (1);
}

