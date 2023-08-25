#include "monty.h"

/**
 * parse - function that parses and reads the bytecode files
 * @fileName: file to be opened
 * @UNUSED: unused pointer to head
 *
 * Return: void
 */
void parse(char *fileName, stack_t **head UNUSED)
{
	FILE *src_code;
	ssize_t read;
	char *line = NULL, *op;
	size_t len = 0;
	unsigned int lineNumber = 1;

	src_code = fopen(fileName, "r");
	if (src_code == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}

	GLOBAL_var.src_code_p = src_code;

	atexit(freeDataStructure);

	while ((read = getline(&line, &len, src_code)) != -1) 
	{
		GLOBAL_var.line = line;
		op = strtok(line, DELIMS);
		if (op != NULL)
			exe_opn(op, head, lineNumber);
		lineNumber++;
	}

    fclose(src_code);
    if (line)
        free(line);
}
