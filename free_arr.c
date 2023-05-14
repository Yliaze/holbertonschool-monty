#include "monty.h"

/**
 * free_arr - Frees a two-dimensional array of strings
 * @freed: The array of strings to be freed
 * This function frees each individual string in the array,
 * and then frees the array itself
 */
void free_arr(char **freed)
{
	int i = 0;

	for (; freed[i] != NULL; i++)
	{
		free(freed[i]);
	}
	free(freed);
}
