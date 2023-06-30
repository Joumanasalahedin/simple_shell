#include "shell.h"

/**
 * print_env - prints
 * @s: string
 * @env: environment
 * Return: (0)
 */

int print_env(char **s, list_t *env)
{
	sh_free_double_ptr(s);
	print_list(env);
	return (0);
}

/**
 * h_getenv - get environment variables
 * @s: string
 * @env: environment
 * Return: environment variable
 */

char *h_getenv(char *s, list_t *env)
{
	int en = 0;
	int vars = 0;

	while (env != NULL)
	{
		en = 0;
		while ((env->var)[en] == s[en])
			en++;
		if (s[en] == '\0' && (env->var)[en] == '=')
			break;
		env = env->next;
	}
	while (s[vars] != '\0')
		vars++;
	vars++;
	return (env_strdup(env->var, vars));
}

/**
 * list_env - linked list calls variables
 * @env: variable
 *
 * Return: list
 */

list_t *list_env(char **env)
{
	list_t *head;
	int en = 0;

	head = NULL;
	while (env[en] != NULL)
	{
		add_node_end(&head, env[en]);
		en++;
	}
	return (head);
}
