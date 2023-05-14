#include "monty.h"

/**
 * atoichecker - Checks if a token is an integer
 * @token: The token to check
 * @line_number: The current line number
 * Return: 0 if the token is an integer
 */
int atoichecker(char *token, int line_number)
{
	int counter = 0;

	for ( ; token[counter] != '\0'; counter++)
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
