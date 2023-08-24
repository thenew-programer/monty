#include "monty.h"


/**
 * do_pall - function that prints all the values in the stack, starting from
 * the top of the stack
 * @stack: pointer to the top of the stack
 * @UNUSED: unused line number
 *
 * Return: void
 */
void do_pall(stack_t **stack, unsigned int line_number UNUSED)
{
	stack_t *h = *stack;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}


/**
 * do_push - function that pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	char *str_num;
	int num;

	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_src_code_line();
		exit(EXIT_FAILURE);
	}

	str_num = strtok(NULL, DELIMS);
	if (str_num == NULL || _isdigit(str_num) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_src_code_line();
		free(newnode);
		exit(EXIT_FAILURE);
	}

	num = atoi(str_num);
	newnode->n = num;
	newnode->prev = NULL;

	if (stack == NULL || *stack == NULL)
	{
		*stack = newnode;
		newnode->next = NULL;
		return;
	}

	newnode->next = *stack;
	(*stack)->prev = newnode;
	*stack = newnode;
}


/**
 * do_pint - function that prints the first element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}


