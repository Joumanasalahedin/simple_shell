#include "shell.h"

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
	if (val == -1)
	{
		illegal_n(s[1], n, env);
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

/**
 * free_linked - free linked list
 * @list: linked list
 */

void free_linked(list_t *list)
{
	list_t *fresh_n;

	while (list != NULL)
	{
		fresh_n = list;
		list = list->next;
		free(fresh_n->v);
		free(fresh_n);
	}
}
