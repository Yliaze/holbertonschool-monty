#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the command
 */
void _push(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if(global_stack->n == 0)
		{
			global_stack->n = (*stack)->n;
		}
	else 
		{
			(*stack)->next = global_stack;
			global_stack = *stack; 
		}
}
