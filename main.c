#include "monty.h"
#include <stdio.h>


global_vars_t GLOBAL_var;
/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument array
 * Return: success or failure
*/

int main(int argc, char **argv)
{
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty <file>\n");
		exit(EXIT_FAILURE);
	}
	GLOBAL_var.top = &head;

	parse(argv[1], &head);
	exit(EXIT_SUCCESS);
}
