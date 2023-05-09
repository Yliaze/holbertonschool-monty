#include "main.h"

/**
 *
 */

char ** cut_line(char **line)
{
	int counter = 0;

	line[counter] = strtok(line[counter], " $");

	while (line[counter])
	{
		counter += 1;	
		line[counter] = strtok(NULL, " $");
	}
	return (line);
}
