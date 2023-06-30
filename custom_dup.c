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
	int length = 0, i;
	char *dup_s;

	if (s == NULL)
	{
		return (NULL);
	}

	while (s[length])
		length++;
	length++;

	dup_s = malloc(sizeof(char) * (length - b));
	if (dup_s == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < (length - b))
	{
		*(dup_s + i) = *(s + b + i);
		i++;
	}
	return (dup_s);
}
