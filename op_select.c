#include "main.h"

/**
 *  *
 *   */
int op_exec(char **line)
{
	int counter = 0;

	instruction_t op_select[] = {
		{"push", _push},
		/*{"pall", _pall},
		 *     {"pint", _pint},
		 *         {"pop", _pop},
		 *             {"swap", _swap},
		 *                 {"add", _add},
		 *                     {"nop", _nop},**/
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

