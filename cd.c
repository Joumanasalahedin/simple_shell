#include "shell.h"

/**
 * concat_str - concatenate two strings of cd
 * @s1: string1
 * @s2: string2
 *
 * Return: concatenated strings
 */

char *concat_str(char *s1, char *s2)
{
	size_t length1 = strlen(s1);
	size_t length2 = strlen(s2);
	char *concat = malloc(length1 + length2 + 2);

	if (concat == NULL)
	{
		printf("failed to allocate. \n");
		return (NULL);
	}
	_strcpy(concat, s1);
	concat[length1] = '=';
	_strcpy(concat + length1 + 1, s2);
	return (concat);
}

/**
 * cd_setenv - set environment for cd before setting
 * @env: environment
 * @n: variable name
 * @directory: path
 *
 *Return: 0
 */

int cd_setenv(list_t **env, char *n, char *directory)
{
	char *c;
	list_t *fresh_n;

	c = concat_str(n, directory);
	if (c == NULL)
	{
		return (-1);
	}
	fresh_n = *env;

	while (!fresh_n)
	{
		if (_strcmp(fresh_n->var, n) == 0)
		{
			free(fresh_n->var);
			fresh_n->var = c;
			return (0);
		}
		fresh_n = fresh_n->next;
	}
	fresh_n = malloc(sizeof(list_t));
	if (fresh_n == NULL)
	{
		printf("allocation failed. \n");
		free(c);
		return (-1);
	}
	fresh_n->var = c;
	fresh_n->next = *env;
	*env = fresh_n;

	return (0);
}

/**
 * cd_home - change directory to home
 * @env: environment
 * @curr: current working directory
 */

void cd_home(list_t **env, char *curr)
{
	char *h = h_getenv("HOME", env);
	char *new_curr = getcwd(NULL, PATH_MAX);

	if (h == NULL)
	{
		printf("Cannot find HOME\n");
		return;
	}
	cd_setenv(env, "OLDPWD", curr);
	free(curr);

	if (access(h, F_OK) == 0)
		chdir(h);
	free(h);
	if (new_curr == NULL)
	{
		printf("Cannot retrieve current working directory\n");
		return;
	}
	cd_setenv(env, "PWD", new_curr);
	free(new_curr);
}
