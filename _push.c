#include "main.h"

/**
 *
 */

void push(char *line)
{
	stack_t new_node = NULL;

	line = atoi(line);

	new_node = malloc(sizeof(stack_t));
	new_node->n = line;
	new_node->prev = NULL;
	new_node->next = NULL;

	if(stack->next != NULL)
	{
		new->next = stack;
		stack->prev = new;
		stack = new;	
	}
	else 
	{
		free(stack);
		stack = new;
	}

}
