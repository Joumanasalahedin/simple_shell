#include "shell.h"

/**
 * cd_atoi - Convert string to integer.
 * @s: char
 *
 * Return: Integer
 */

int cd_atoi(char *s)
{
	int j = 0;
	unsigned int sum = 0;

	if (s == NULL)
		return (0);

	while (s[j] != '\0')
	{
		if (s[j] >= '0' && s[j] <= '9')
			sum = sum * 10 + (s[j] - '0');
		else
			return (-1);
		j++;
	}
	return (sum);
}

/**
 * sh_exit - exit the shell
 * @s: strint to hsh
 * @env: variable
 * @n: user command input
 * @cmd: command
 * Return: exit shell
 */

int sh_exit(char **s, char **cmd, list_t *env, int n)
{
	int val = 0;

	if (s[1] != NULL)
		val = cd_atoi(s[1]);
	else
		val = 0;
	if (val == -1)
	{
		illegal_n(s[1], n, &env);
		sh_free_double_ptr(s);
		return (2);
	}
	sh_free_double_ptr(s);
	free_linked(env);
	if (cmd != NULL)
		sh_free_double_ptr(cmd);
	exit(val);
}
/**
 * exit_c - linked list before exiting
 * @s: typed command
 * @env: environment
 */

void exit_c(char **s, list_t *env)
{
	sh_free_double_ptr(s);
	free_linked(env);
	_exit(0);
}
