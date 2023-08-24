#include "monty.h"

/**
 * do_add - function that adds the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_add(stack_t **stack, unsigned int line_number)
{
	int a, b, sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;
	sum = a + b;

	do_pop(stack, line_number);

	(*stack)->n = sum;
}