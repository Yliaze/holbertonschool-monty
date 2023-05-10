#include "main.h"

/**
* cut_line - Splits a string into tokens using
* whitespace and '$' as delimiters.
* @line: The string to be tokenized.
*
* Return: An array of strings representing the tokens.
**/

char **cut_line(char **line)
{
	//int counter = 0;
	char *token;
	char **save_token;
	int counter = 0;

	token = strtok(*line, " $");

	while (token != NULL)
	{	
		save_token[counter] = strdup(token);
		if (save_token[counter] == NULL)
		{
			//free_arr (save_token);
			//print une error
		}
		token = strtok(NULL, " $");
		counter++;
	}
	return (save_token);
}
