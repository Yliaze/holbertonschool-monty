#include "main.h"

int main(int argc, char** argv)
{
	FILE *fptr = NULL;
	char** line = NULL;
	size_t buffsize = 32;
	size_t read = 0;
	int line_counter = 0;
	stack_t *new_node = NULL;


	//stack = malloc(sizeof(stack_t));

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

	

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return;
	}

	new_node->n = iline;
	new_node->prev = NULL;
	new_node->next = NULL;


	}
	fclose(fptr);
	if (line)
	{
		free(line);
	}
	printf(" nombre de lignes : %d", line_counter);
	exit(EXIT_SUCCESS);
}


int op_exec(char **line)
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
		if (strcmp(op_select[counter].opcode, line[0]) == 0)
		{
			op_select[counter].f(line[1]);
			break;
		}
		counter++;
	}
	return (0);
}
