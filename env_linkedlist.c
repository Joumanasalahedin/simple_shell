#include "shell.h"

/**
 * env_linked - print env linked list
 * @h: list
 * Return: size
 */

size_t env_linked(list_t *h)
{
	int num = 0;
	int e = 0;
	list_t *e_list = h;

	if (h == NULL)
		return (0);
	while (e_list != NULL)
	{
		if (e_list->v == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			e = 0;
			while ((e_list->v)[e] != '\0')
				e++;
			write(STDOUT_FILENO, e_list->v, e);
			write(STDOUT_FILENO, "\n", 1);
		}
		e_list = e_list->next;
		num++;
	}
	return (num);
}
