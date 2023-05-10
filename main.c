#include "main.h"

int op_exec(stack_t *new_node, char *line, int n, unsigned int line_number)
{
	int counter = 0;

	instruction_t op_select[] = {
		{"push", _push},
		/*{"pall", _pall},
		 *{"pint", _pint},
		 *{"pop", _pop},
		 *{"swap", _swap},
		 *{"add", _add},
		 *{"nop", _nop},**/
		{"\0", NULL}
	};

	while (op_select[counter].opcode != "\0")
	{
		if (strcmp(op_select[counter].opcode, line) == 0)
		{
			op_select[counter].f(&new_node, line_number);
			break;
		}
		counter++;
	}
	return (0);
}

int main(int argc, char** argv)
{
	FILE *fptr = NULL;
	char** line = NULL;
	int iline = 0;
	size_t buffsize = 512;
	size_t read = 0;
	int line_number = 0;
	stack_t *new_node = NULL;
	int counter = 0;
	char **token;

	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		//fclose(fptr);
		exit(EXIT_FAILURE);
	}
	if (argv[1] == NULL || fptr == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (buffsize == 0)
	{
		perror("Could not initate buffer");
		return (0);
	}

	line = calloc(sizeof(char), buffsize);
	
	while ((read = getline(line,&buffsize, fptr)) != -1)
	{
		line_number++;
		token = cut_line(line);
		//while (line[1][counter] != "\0")
		//{
		iline = *token[1] + 0;
		//}
		new_node = create_node(iline);
		op_exec(new_node, line[0], iline, line_number);
	}
	fclose(fptr);
	if (line)
	{
		free(line);
	}
	printf("nombre de lignes : %d", line_number);
	exit(EXIT_SUCCESS);
}



