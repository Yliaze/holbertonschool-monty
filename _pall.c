#include "main.h"

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
    printf("tototZ\n");

    printf("pall = %d\n", (tmp->n));

    if (tmp->n != 0)
        {
         printf("c'est != 0\n");    
        while (tmp != NULL)
            {
            printf("plusieur\n"); 
            printf("%d\n",tmp->n);
            tmp = tmp->next;
            printf("totota\n");
            }
        }
    printf("tototor\n");
}