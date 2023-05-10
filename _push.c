#include "main.h"

/**
 *  *
 *   */

void _push(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *new_node = NULL;

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
