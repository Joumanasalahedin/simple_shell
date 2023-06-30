#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */

typedef struct list
{
	char *var;
	struct list *next;

} list_t;

void n_found(char *s, int c_f, list_t *env);
void *re_alloc(void *ptr, unsigned int o_mem, unsigned int n_mem);
int builtin_c(char **toks, list_t *env, int n);
char *int_string(int num);
int number_len(int num);
int search_env(list_t *env, char *s);
int sh_setenv(list_t **env, char **s);
int sh_unsetenv(list_t **env, char **s);
char *h_getenv(char *s, list_t *env);
char *env_strdup(char *s, int b);
list_t *list_env(char **env);
void exit_c(char **s, list_t *env);
void illegal_n(char *s, int cmd, list_t *env);
int execute(char **comand, list_t *env, int num);
int run_shell(char **environ);
void sh_free_double_ptr(char **s);
int sh_exit(char **s, char **cmd, list_t *env, int n);
int print_env(char **s, list_t *env);
int cd_atoi(char *s);
void ctrl_c(int n);
void ctrl_d(int i, char *command, list_t *env);
char *ignore_spaces(char *str);
size_t _getline(char **str);
char *find_exec(char *command, list_t *env);
char *s_ignore(char *str);
void non_interactive(list_t *env);

/** strtok **/
int token_length(char *input, int position, char delim);
int count_delim(char *input, char delim);
char *ignore_delim(char *str, char delim);
char **_strtok(char *str, char *delim);
int c_delims(char *str, char delim);
char **token_string(char *str, char *delim);

/** linked list **/
size_t print_list(list_t *h);
list_t *add_node_end(list_t **head, char *str);
int delete_node_at_index(list_t **head, int index);
void free_linked(list_t *list);

/** string manipulation **/
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);

#endif
