#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the command
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	stack_t *tmp = global_stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	global_stack = global_stack->next;
	if (global_stack != NULL)
		global_stack->prev = NULL;
	free(tmp);
}
