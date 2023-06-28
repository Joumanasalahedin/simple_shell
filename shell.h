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
#include <limits.h>

#define TOK_DELIM " \t\n"
#define ENV_DELIM "="
#define BUFSIZE 64
extern char **environ;

/**
 * struct list - linked list for env variables
 * @v: holds env variable string
 * @next: next node
 */
typedef struct list
{
	char *v;
	struct list *next;
} list_t;

char *cd_strdup(char *s, int b);
void cd_home(list_t **env, char *curr);
char *concat_str(char *s1, char *s2);
int cd_setenv(list_t **env, char *n, char *directory);
int search_env(list_t *env, char *s);
int sh_unsetenv(list_t **env, char **s);
int sh_setenv(list_t **env, char **s);
list_t *sh_add_node_end(list_t **head, char *s);
int delete_nodeint_at_index(list_t **head, int index);
char *sh_getenv( char *s, list_t **env);
char *get_path(char *command);
int command_args(char *command);
char **shell_split_line(char *command);
char *shell_read_line(void);
int execute(char **args);
char *_getline(void);
void sh_free_double_ptr(char **s);
int sh_cd(char **args);
int sh_exit(void);
int sh_env(char **args);
int sh_help(char **args);

/* helper functions */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *delim);

#endif /* SHELL_H */
