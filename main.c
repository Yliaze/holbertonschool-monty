#include "monty.h"

stack_t *global_stack;

int op_exec(stack_t *new_node, char *line, unsigned int line_number)
{
	int counter = 0;

	instruction_t op_select[] = {
		{"push", _push},
		{"pall", _pall},
		 /*{"pint", _pint},
		 *{"pop", _pop},
		 *{"swap", _swap},
		 *{"add", _add},
		 *{"nop", _nop},**/
		{'\0', NULL}
	};

	while (op_select[counter].opcode != 0)
	{
		if (strcmp(op_select[counter].opcode, line) == 0)
		{
		
			op_select[counter].f(&new_node, line_number);
			break;
		}
		counter++;
	}
	if (op_select[counter].f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
		exit(EXIT_FAILURE);
	}
	return(0);
}

int main(int argc, char** argv)
{
	FILE *fptr = NULL;
	char *line = NULL, **token;
	int iline = 0, read = 0, line_number = 0;
	size_t buffsize = 0;
	stack_t *new_node = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fptr = fopen(argv[1], "r");

	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line,&buffsize, fptr)) != -1)
	{
		new_node = NULL;
		line_number++;		
		token = cut_line(line);
		
		if (token && token[1])
		{
			// Replace is digit by your own custom function that help to check each digit and that handle negative numbers
			if (atoichecker(token[1], line_number) == 0)
			{
				iline = atoi(token[1]);
				new_node = create_node(iline);
			}
		}
		
		op_exec(new_node, line, line_number);
	}
	fclose(fptr);
	if (new_node)
		free(new_node);
	free_list(global_stack);
	if (token)
	{
		free_arr(token);
		free(token);
	}
	if (line)
	{
		free(line);
	}
	exit(EXIT_SUCCESS);
}



