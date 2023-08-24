#ifndef MONTY_H
#define MONTY_H

#define DELIMS " \t\n\r"
#define UNUSED __attribute__((unused))

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t stack;
ssize_t getline(char **lineptr, size_t *n, FILE *stream);


/* helper functions */
void parse(char *fileName, stack_t **head);
void dropnl(char *src);
void exe_opn(char *operation, stack_t **head, unsigned int line_number);
int _isdigit(char *str);
void freeDataStructure(void);
void free_src_code_line(void);

/* instructions */
void do_push(stack_t **stack, unsigned int line_number);
void do_pall(stack_t **stack, unsigned int line_number);
void do_pint(stack_t **stack, unsigned int line_number);

/**
 * struct global_vars_s - global structure
 * @top: points to the top of the stack
 * @src_code_p: points to the file pointer
 * @line: points to the current line of the script
 *
 */

typedef struct global_vars_s
{
	stack_t **top;
	FILE *src_code_p;
	char *line;
} global_vars_t;

extern global_vars_t GLOBAL_var;

#endif /* MONTY_H */
