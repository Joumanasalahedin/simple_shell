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
  * struct list - list for env variables
  * @var: env variable string
  * @next: pointer to next node
  */
typedef struct list
{
	char *var;
	struct list *next;
} list_t;

int execute(char **comand, list_t *env, int num);
int run_shell(char **environ);
void sh_free_double_ptr(char **s);
int sh_exit(char **s, char **cmd, list_t *env, int n);
int cd_atoi(char *s);
void ctrl_c(int n);
void ctrl_d(int i, char *command, list_t *env);
char *ignore_spaces(char *str);

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
char *_strtok(char *str, const char *delim);

#endif
