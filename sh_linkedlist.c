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
 * delete_nodeint_at_index - delets node at index
 * @head: pointer
 * @index: idx node
 *
 * Return: 1 or -1
 */

int delete_nodeint_at_index(list_t **head, int index)
{
	int j = 0;
	list_t *fresh_n;
	list_t *n_node;

	fresh_n = *head;
	if (fresh_n == NULL)
	{
		return (-1);

		if (index == 0)
		{
			*head = fresh_n->next;
			free((fresh_n)->v);
			free(fresh_n);
			return (1);
		}
	}
	while (j < index)
	{
		if (fresh_n == NULL)
			return (-1);
		fresh_n = fresh_n->next;
		j++;
	}
	n_node = fresh_n->next;
	fresh_n->next = n_node->next;
	free(n_node->v);
	free(n_node);
	return (1);
}

/**
 * *sh_add_node_end - add end node linked list
 * @head: ptr
 * @s: string
 *
 * Return: new ptr
 */

list_t *sh_add_node_end(list_t **head, char *s)
{
	list_t *n_node;
	list_t *fresh_n;

	n_node = malloc(sizeof(list_t));
	if (n_node == NULL)
		return (NULL);

	n_node->v = _strdup(s);
	n_node->next = NULL;

	fresh_n = *head;
	if (!fresh_n)
	{
		while (fresh_n->next != NULL)
		{
			fresh_n = fresh_n->next;
		}
		fresh_n->next = n_node;
	}
	else
	{
		*head = n_node;
	}
	return (*head);
}
