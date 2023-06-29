#include "shell.h"

/**
 * env_strdup - custom duplicate
 * @s: string
 * @b: bytes
 *
 * Return: string duplicate
 */

char *env_strdup(char *s, int b)
{
	size_t length = strlen(s);
	char *dup_s = malloc(sizeof(char) * (length - b + 1));

	if (s == NULL)
	{
		return (NULL);
	}
	if (length <= (size_t) b)
	{
		return (NULL);
	}
	if (dup_s == NULL)
	{
		return (NULL);
	}
	strcpy(dup_s, s + b);
	return (dup_s);
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
	int var = 0;

	while (env != NULL)
	{
		while ((env->v)[en] == s[en])
			en++;
		if (s[en] == '\0' && (env->v)[en] == '=')
			break;
		env = env->next;
	}
	if (env == NULL)
		return (NULL);
	while (s[var] != '\0')
		var++;
	var++;
	return (env_strdup(env->v, var));
}

/**
 * pr_env - prints
 * @s: string
 * @env: environment
 * Return: (0)
 */

int pr_env(char **s, list_t *env)
{
	sh_free_double_ptr(s);
	env_linked(env);
	return (0);
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
		sh_add_node_end(&head, env[en]);
		en++;
	}
	return (head);
}
