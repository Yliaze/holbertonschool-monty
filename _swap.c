#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the command
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	stack_t *tmp = NULL;

	if (global_stack == NULL || global_stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = global_stack->next;
	global_stack->next = tmp->next;
	tmp->next = global_stack;
	global_stack = tmp;
}
