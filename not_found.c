#include "shell.h"

/**
 * n_found - write error
 * @s:string
 * @c_f: typed command
 * @env: variable write hsh
 */

void n_found(char *s, int c_f, list_t **env)
{
	int sum = 0;
	char *hsh, *numb;

	hsh = h_getenv("_", env);

	while (hsh[sum] != '\0')
		sum++;
	write(STDOUT_FILENO, hsh, sum);
	free(hsh);
	write(STDOUT_FILENO, ": ", 2);
	numb = int_string(c_f);
	sum = 0;

	while (numb[sum] != '\0')
		sum++;
	write(STDOUT_FILENO, numb, sum);
	free(numb);
	write(STDOUT_FILENO, ": ", 2);
	sum = 0;

	while (s[sum] != '\0')
		sum++;
	write(STDOUT_FILENO, s, sum);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}
