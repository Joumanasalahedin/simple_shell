#include "shell.h"

/**
 * sh_unsetenv - remove env variable
 * @env: environment
 * @s: string command
 *
 *Return: 0
 */

int sh_unsetenv(list_t **env, char **s)
{
	int e = 0;
	int idx = 0;

	if (s[1] == NULL)
	{
		write(STDOUT_FILENO, "Few args\n", 10);
		sh_free_double_ptr(s);
		return (-1);
	}
	idx = search_env(*env, s[1]);
	sh_free_double_ptr(s);

	if (idx == -1)
	{
		write(STDOUT_FILENO, "Can't find\n", 12);
		return (-1);
	}
	e = delete_nodeint_at_index(env, idx);
	if (e == -1)
	{
		write(STDOUT_FILENO, "Can't find\n", 12);
		return (-1);
	}
	return (0);
}

/**
 * sh_setenv - modify env variable
 * @env: environment
 * @s: string
 *
 * Return: 0 or 1
 */

int sh_setenv(list_t **env, char **s)
{
	int e = 0;
	int idx = 0;
	char *c;
	list_t *fresh_n;

	if (s[1] == NULL || s[2] == NULL)
	{
		write(STDOUT_FILENO, "Few args\n", 10);
		sh_free_double_ptr(s);
		return (-1);
	}
	c = _strdup(s[1]);
	c = _strcat(c, "=");
	c = _strcat(c, s[2]);

	idx = search_env(*env, s[1]);
	if (idx == -1)
	{
		sh_add_node_end(env, c);
	}
	else
	{
		for (e = 0; e < idx; e++)
		{
			fresh_n = fresh_n->next;
		}
		free(fresh_n->v);
		fresh_n->v = _strdup(c);
	}
	free(c);
	sh_free_double_ptr(s);
	return (0);
}
