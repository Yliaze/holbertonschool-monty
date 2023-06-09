#include "monty.h"

stack_t *global_stack;

/**
 * op_exec - Selects and executes an opcode function
 * based on the input line
 * @new_node: A pointer to the top of the stack
 * @line: A string representing the opcode to execute
 * @line_number: An unsigned integer representing the current
 * line number
 * Return: Always returns 0
 */
int op_exec(stack_t *new_node, char *line, unsigned int line_number)
{
	int counter = 0;

	instruction_t op_select[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
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
	return (0);
}

/**
 * main - Entry point for Monty bytecode interpreter
 * @argc: The number of arguments passed
 * @argv: An array of strings containing the arguments
 * Return: Always 0 (success) or EXIT_FAILURE (failure)
 */
int main(int argc, char **argv)
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
	while ((read = getline(&line, &buffsize, fptr)) != -1)
	{
		new_node = NULL;
		line_number++;
		token = cut_line(line);
		if (!token[0])
			continue;
		if (token && token[1] && strcmp(token[0], "push") == 0)
		{
			if (atoichecker(token[1], line_number) == 0)
			{
				iline = atoi(token[1]);
				new_node = create_node(iline);
			}
		}
		op_exec(new_node, token[0], line_number);
		/**
		* if (new_node != NULL)
		* {
		* free(new_node);
		* }
		*/
		free_arr(token);
	}
	if (line)
		free(line);
	free_list(global_stack);
	fclose(fptr);
	exit(EXIT_SUCCESS);
}



