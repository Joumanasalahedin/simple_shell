#include "shell.h"

/**
 * sh_free_double_ptr - free malloced arrays
 * @s: string
 *
 */

void sh_free_double_ptr(char **s)
{
	char **tmp = s;

	if (s == NULL)
	{
		return;
	}
	while (!*tmp)
	{
		free(*tmp);

		*tmp = NULL;
		tmp++;
	}
	free(s);
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
		free(fresh_n->var);
		free(fresh_n);
	}
}

/**
 * illegal_n - print error
 * @s: string
 * @cmd: typed command
 * @env: environment
 */

void illegal_n(char *s, int cmd, list_t *env)
{
	int sum = 0;
	char *hsh = NULL, *number = NULL;

	hsh = h_getenv("_", env);

	while (hsh[sum] != '\0')
		sum++;

	write(STDOUT_FILENO, hsh, sum);
	free(hsh);
	write(STDOUT_FILENO, ": ", 2);
	number = int_string(cmd);
	sum = 0;

	while (number[sum] != '\0')
		sum++;
	write(STDOUT_FILENO, number, sum);
	free(number);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: illegal number: ", 22);
	sum++;

	while (s[sum] != '\0')
		sum++;
	write(STDOUT_FILENO, s, sum);
	write(STDOUT_FILENO, "\n", 1);
}
