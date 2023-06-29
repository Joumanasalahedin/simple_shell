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

void sh_free_double_ptr(char **s);
void free_linked(list_t *list);
int sh_exit(char **s, char **cmd, list_t *env, int n);
int cd_atoi(char *s);
void illegal_n(char *s, int cmd, list_t *env);



#endif
