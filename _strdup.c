#include "shell.h"
#include <stdlib.h>

/**
 * _strdup - duplicate a string using malloc
 * @str: string
 *
 * Return: NULL or  pointer to the strdup
 */

char *_strdup(char *str)
{
	char *arr;
	int s, d;

	if (str == NULL)
		return (NULL);

	for (s = 0; str[s] != '\0'; s++)
		;

	arr = malloc(s * sizeof(*arr) + 1);
	if (arr == NULL)
		return (NULL);

	for (d = 0; d < s; d++)
		arr[d] = str[d];

	arr[d] = '\0';

	return (arr);
}
