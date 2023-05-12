#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the command
 */
void _swap(stack_t **stack, unsigned int line_number)
{
    (void) line_number;
    stack_t *tmp = NULL;

    tmp->n = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = tmp->n;
}