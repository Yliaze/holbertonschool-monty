#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number being executed
 */
void _add(stack_t **stack, unsigned int line_number)
{

	(void) stack;
	stack_t *tmp = global_stack;

	if (global_stack == NULL || global_stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp->next->n += tmp->n;
	_pop(stack, line_number);
}
