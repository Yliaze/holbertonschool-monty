#include "monty.h"

/**
 * create_node - Creates a new node for a doubly linked list.
 * @n: The value to store in the new node.
 *
 * Return: A pointer to the new node.
 */
stack_t *create_node(int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
