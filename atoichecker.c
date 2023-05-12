#include "monty.h"

/**
 * 
 * Return: 0 on success
*/

int atoichecker(char* token, int line_number)
{
    int counter = 0;

    for (;token[counter] != '\0'; counter++)
    {
        if (token[counter] == '-')
        {
            counter++;
        }
        if (isdigit(token[counter]) == 0)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }
    return (0);
}