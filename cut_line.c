#include "monty.h"

/**
* cut_line - Splits a string into tokens using delimiters.
* @line: The string to be tokenized.
*
* Return: An array of strings representing the tokens.
**/
char **cut_line(char *line)
{
	char **save_token;
	int counter = 0;
	char *token = NULL;

	
	save_token = malloc(3 * sizeof(char*));
	if (save_token == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " $\n\t");

	while (token != NULL)
	{	
		save_token[counter] = strdup(token);
		token = strtok(NULL, " $\n\t");
		counter++;
	}
	free(token);
	save_token[counter] = NULL;
	return (save_token);
}
