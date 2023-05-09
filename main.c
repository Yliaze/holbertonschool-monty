#include "main.h"

int main(int argc, char** argv)
{
	FILE *fptr = NULL;
	char** line = NULL;
	size_t buffsize = 32;
	ssize_t read = 0;
	int line_counter = 0;

	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fclose(fptr);
		EXIT_FAILURE;
	}
	if (argv[1] == NULL || fptr == NULL)
	{
		EXIT_FAILURE;
	}

	line = malloc(buffsize * sizeof(char));
	if (buffsize == 0)
	{
		perror("Could not initate buffer");
		return (0);
	}
	while ((read = getline(&*line,&buffsize, fptr)) != -1);
	{
		line_counter++;
		line = cut_line(line);
		op_exec(line);
	}
	fclose(fptr);
	if (line)
	{
		free(line);
	}
	printf(" nombre de lignes : %d", line_counter);
	exit(EXIT_SUCCESS);
}

