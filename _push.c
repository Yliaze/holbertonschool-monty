#include "main.h"

/**
 * _push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the command
 */
void _push(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	// global_stack = *global_stack;
	if(global_stack->next == NULL)
		{
			global_stack = *stack;
			printf("ça marche = %d\n", global_stack->n);
		}
	else 
		{
			(*stack)->next = global_stack;
			*stack = global_stack; 
			/*free(stack);**/
		}
}
