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
	char *dup_str;
	int i, length = 0;

	if (str == NULL)
		return (NULL);
	
	while (*(str + length))
		length++;
	length++;

	dup_str = malloc(sizeof(char) * length);
	
	if (dup_str == NULL)
		return (NULL);

	i = 0;
	while (i < length)
	{
		*(dup_str + i) = *(str + i);
		i++;
	}
	return (dup_str);
}
