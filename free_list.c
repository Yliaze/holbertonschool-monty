#include "monty.h"

/**
 * free_list - free a double linked list
 * @head: The original linked list.
 * Return: 0
 */
void free_list(stack_t *head)
{
	stack_t *node = head;
	stack_t *tmp = NULL;

	while (node != NULL)
	{
        tmp = node;	
		node = node->next;
        free(tmp);
	}
    head = NULL;
}