#include "main.h"

/**
 *
 */

stack_t **create_node(int n)
{
	stack_t **new_node = NULL;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	(*new_node)->n = n;
	(*new_node)->prev = NULL;
	(*new_node)->next = NULL;

	return (new_node);
}
