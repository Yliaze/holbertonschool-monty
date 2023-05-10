#include "main.h"

/**
 *  *
 *   */

void _push(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *new_node = NULL;
	int iline;
	char *line;

	iline = atoi(line);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return;
	}

	new_node->n = iline;
	new_node->prev = NULL;
	new_node->next = NULL;

	if((*stack)->next != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;  
	}
	else 
	{
		/*free(stack);**/
		*stack = new_node;
	}
}
