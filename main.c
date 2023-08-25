#include "monty.h"
#include <stdio.h>
global_vars_t GLOBAL_var;

int main(int argc, char **argv)
{
	stack_t *head = NULL;
	GLOBAL_var.top = &head;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty <file>\n");
		exit(EXIT_FAILURE);
	}

	parse(argv[1], &head);
	exit(EXIT_SUCCESS);

}
