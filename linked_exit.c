#include "shell.h"

/**
 * number_len - count zeros
 * @num: numbers
 * Return: count of numbers
 */

int number_len(int num)
{
	int sum = 0;

	if (num == 0)
		return (1);
	else if (num < 0)
		num = -num;
	while (num > 0)
	{
		num /= 10;
		sum++;
	}
	return (sum);
}

/**
 * int_string - turns int to string
 * @num: integer
 * Return: int to string
 */

char *int_string(int num)
{
	char *result;
	int j = 0;
	int n = 0;
	int k;
	int sign = num;
	int ten = 1;

	if (num < 0)
		j = 1;
	result = malloc(sizeof(char) * (number_len(sign) + 2 + j));
	if (result == NULL)
		return (NULL);
	if (num < 0)
	{
		result[n] = '-';
		n++;
	}
	for (k = 0; sign > 9 || sign < -9; k++)
	{
		sign /= 10;
		ten *= 10;
	}
	for (sign = num; k >= 0; k--)
	{
		if (sign < 0)
		{
			result[n] = (sign / ten) * -1 + '0';
			n++;
		}
		else
		{
			result[n] = (sign / ten) + '0';
			n++;
		}
		sign %= ten;
		ten /= 10;
	}
	result[n] = '\0';
	return (result);
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
