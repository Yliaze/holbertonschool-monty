#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the command
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int check;
	int value;
	
	if (stack == NULL || !*stack)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (global_stack == NULL)
			global_stack = *stack;
	else 
		{
			(*stack)->next = global_stack;
			global_stack = *stack; 
		}
}