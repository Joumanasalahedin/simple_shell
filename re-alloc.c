#include "shell.h"

/**
 * re_alloc - allocate memory
 * @ptr: pointer
 * @o_mem: previously allocated
 * @n_mem: reallocate
 * Return: reallocated memory
 */

void *re_alloc(void *ptr, unsigned int o_mem, unsigned int n_mem)
{
	void *pointer;
	unsigned int m;

	if (n_mem == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (n_mem == o_mem)
		return (ptr);
	if (ptr == NULL)
	{
		pointer = malloc(n_mem);
		if (pointer == NULL)
			return (NULL);
		else
			return (pointer);
	}

	pointer = malloc(n_mem);
	if (pointer == NULL)
		return (NULL);
	for (m = 0; m < o_mem && m < n_mem; m++)
		*((char *)pointer + m) = *((char *)ptr + m);
	free(ptr);

	return (pointer);
}
