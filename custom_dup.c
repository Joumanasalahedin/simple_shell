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
