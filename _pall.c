#include "monty.h"

/**
 * _pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: double pointer to the stack
 * @line_number: line number of the command
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	stack_t *tmp = NULL;

	tmp = global_stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
