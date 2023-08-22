#include "monty.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *src_code;
	size_t len = 0;
	ssize_t read;
	char *line = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty <file>\n");
		exit(EXIT_FAILURE);
	}
	src_code = fopen(argv[1], "r");
	if (!src_code)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}
    while ((read = getline(&line, &len, src_code)) != -1) {
		if (line[read - 1] == 10)
 			line[read - 1] = 0;
        printf("Retrieved line of length %lu:\n", strlen(line));
        printf("%s\n", line);
    }

    fclose(src_code);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
