#include "monty.h"

/**
 * _pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: double pointer to the stack
 * @line_number: line number of the command
 */
void _pall(stack_t **stack, unsigned int ligne_number)
{
    stack_t *tmp = NULL;

    tmp = global_stack;

    if (tmp->n != 0)
        {   
        while (tmp != NULL)
            {
            printf("%d\n",tmp->n);
            tmp = tmp->next;
            }
        }
}