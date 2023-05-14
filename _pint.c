#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: doubly linked list storing the data
 * @line_number: line number of the command
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (global_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", global_stack->n);
}
