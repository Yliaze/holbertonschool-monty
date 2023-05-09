#include "main.h"

/**
 *  *
 *   */

void _push(char *line)
{
	stack_t new_node;
	int iline;

	iline = atoi(line);

	new_node = (stack_t *) malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return;
	}

	new_node->n = iline;
	new_node->prev = NULL;
	new_node->next = NULL;

	if(stack->next != NULL)
	{
		new->next = stack;
		stack->prev = new_node;
		stack = new_node;  
	}
	else 
	{
		/*free(stack);**/
		stack = new_node;
	}
}
