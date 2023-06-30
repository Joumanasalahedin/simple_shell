#include "shell.h"

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
 * number_len - count zeros
 * @num: numbers
 * Return: count of numbers
 */

int number_len(int num)
{
	int sum = 0;
	int n = num;

	while (n > 9 || n < -9)
	{
		n /= 10;
		sum++;
	}
	return (sum);
}
