#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the command
 */
void _push(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	int check;
	int value;
	

	if(global_stack->n == 0)
		{
			global_stack->n = (*stack)->n;
		}
	else 
		{
			(*stack)->next = global_stack;
			global_stack = *stack; 
		}
	
	value = (*stack)->n;
	check = isdigit(value + '0');
	
	if (check == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}