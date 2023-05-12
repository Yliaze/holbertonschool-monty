#include "monty.h"

/*
*
*/

void free_arr(char **freed)
{
    int i = 0;

    for (; freed[i] != NULL; i++)
    {
        free(freed[i]);
    }
    free(freed);
}