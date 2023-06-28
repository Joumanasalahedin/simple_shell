#include "shell.h"
#include <stdlib.h>

/**
 * sh_exit - exit the shell
 * @args: arguments
 * Return: 2 and exit shell
 */

int sh_exit(char **args)
{
	if (args && args[1])
	{
		int status = (cd_atoi(args[1]));
		exit(status);
	}
	else
	{
		exit(2);
	}
}

/**
 * cd_atoi - Convert string to integer.
 * @s: char
 *
 * Return: Integer
 */

int cd_atoi(char *s)
{
	int j = 0;
	int max = 1;
	int min = 0;

	while (s[j] == ' ')
		j++;
	if (s[j] == '-')
	{
		max = -1;
		j++;
	}
	else if (s[j] == '+')
	{
		j++;
	}
	while (s[j] >= '0' && s[j] <= '9')
	{
		min = min * 10 + (s[j] - '0');
		j++;
	}
	return (max * min);
}
