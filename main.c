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
	char *line = NULL, **token;
	int iline = 0, read = 0, line_number = 0, counter = 0;
	size_t buffsize = 0;
	stack_t *new_node = NULL;

	global_stack = calloc(3, sizeof(stack_t));
	global_stack->n = 0;
	global_stack->next = NULL;
	global_stack->prev = NULL;

	fptr = fopen(argv[1], "r");

	if (fptr == NULL)
	{
		//fclose(fptr);
		exit(EXIT_FAILURE);
	}
	if (argv[1] == NULL || fptr == NULL)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line,&buffsize, fptr)) != -1)
	{
	
		line_number++;		
		token = cut_line(line);
		if (token[1])
		{
			iline = atoi(token[1]);
		}
		new_node = create_node(iline);		
		op_exec(new_node, line, line_number);
	}
	fclose(fptr);
	if (line)
	{
		free(line);
	}
	exit(EXIT_SUCCESS);
}



