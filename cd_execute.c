#include "shell.h"

/**
 * cd_exec - execute
 * @env: environment
 * @curr: cwd
 * @directory: path changer
 * @s: string
 * @num: number
 * Return: 0 or 2
 */

int cd_exec(list_t **env, char *directory, char *curr, char *s, int num)
{
	int j = 0;

	if (access(directory, F_OK) == 0)
	{
		cd_setenv(env, "OLDPWD", curr);
		free(curr);
		chdir(directory);
		curr = NULL;
		curr = getcwd(curr, 0);
		cd_setenv(env, "PWD", curr);
		free(curr);
	}
	else
	{
		_cd_to(s, num, env);
		free(curr);
		j = 2;
	}
	return (j);
}

/**
 * ch_cd - change directory
 * @s: string
 * @num: number
 * @env: environment
 * Return: 0 or 2
 */

int ch_cd(char **s, list_t **env, int num)
{
	char *direct = NULL;
	char *curr = NULL;
	int exit_st = 0;

	curr = getcwd(curr, 0);
	if (s[1] != NULL)
	{
		if (s[1][0] == '~')
		{
			direct = h_getenv("HOME", env);
			direct = concat_str(direct, s[1]);
		}
		else if (s[1][0] == '-')
		{
			if (s[1][1] == '\0')
				direct = h_getenv("OLDPWD", env);
		}
		else
		{
			if (s[1][0] != '/')
			{
				direct = getcwd(direct, 0);
				direct = _strcat(direct, "/");
				direct = _strcat(direct, s[1]);
			}
			else
				direct = _strdup(s[1]);
		}
		exit_st = cd_exec(env, curr, direct, s[1], num);
		free(direct);
	}
	else
		cd_home(env, curr);
	sh_free_double_ptr(s);
	return (exit_st);
}
/**
 * _cd_to - print error
 * @s: string
 * @cmd: typed command
 * @env: environment
 */

void _cd_to(char *s, int cmd, list_t **env)
{
	int sum = 0;
	char *hsh = NULL, *number;

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
	write(STDOUT_FILENO, "cd: can't cd ", 16);
	sum = 0;

	while (s[sum] != '\0')
		sum++;
	write(STDOUT_FILENO, s, sum);
	write(STDOUT_FILENO, "\n", 1);
}
