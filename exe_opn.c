#include "monty.h"

/**
 * exe_opn - function that executes opcodes
 * @op_cmd: opcode commamd
 * @head: pointer to head
 * @line_number: line number
 *
 * Return: void
 */
void exe_opn(char *op_cmd, stack_t **head, unsigned int line_number)
{
	int i;
	instruction_t all_ops[] = {
		{"push", do_push},
		{"pall", do_pall},
		{"pint", do_pint},
		{NULL, NULL}
	};

	for (i = 0; all_ops[i].opcode; i++)
	{
		if (strcmp(op_cmd, all_ops[i].opcode) == 0)
		{
			all_ops[i].f(head, line_number);
			return;
		}
	}

	if (op_cmd[0] != '#' && strlen(op_cmd) != 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number,op_cmd);
		free_src_code_line();
		exit(EXIT_FAILURE);
	}
}
