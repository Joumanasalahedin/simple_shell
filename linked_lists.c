#include "shell.h"

/**
  * print_list - prints linked list
  * @h: linked list
  * Return: linked list size
  */

size_t print_list(list_t *h)
{
	list_t *current = h;
	size_t count = 0, length = 0;

	while (current != NULL)
	{
		if (current->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)\n", 6);
		}
		else
		{
			while (current->var[length] != '\0')
				length++;

			write(STDOUT_FILENO, current->var, length);
			write(STDOUT_FILENO, "\n", 1);
		}
		current = current->next;
		count++;
	}

	return (count);
}

/**
  * add_node_end - add node to end of list
  * @head: pointer to head of list
  * @str: new node data
  * Return: pointer to new list
  */

list_t *add_node_end(list_t **head, char *str)
{
	list_t *new_node;
	list_t *current;

	if (head == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->var = _strdup(str);
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}

	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;

		current->next = new_node;
	}

	return (*head);
}

/**
  * delete_node_at_index - removing node at index
  * @head: pointer to head of list
  * @index: input index
  * Return: 1 (Success)
  */

int delete_node_at_index(list_t **head, int index)
{
	list_t *temp;
	list_t *current, *previous;
	int count = 0;

	if (*head == NULL || index < 0)
	{
		return (-1);
	}

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp->var);
		free(temp);
		return (1);
	}

	current = *head;
	previous = NULL;

	while (current != NULL)
	{
		if (count == index)
		{
			previous->next = current->next;
			free(current->var);
			free(current);
			return (-1);
		}

		previous = current;
		current = current->next;
		count++;
	}

	return (-1);
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
