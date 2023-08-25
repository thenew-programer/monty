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


/**
 * do_sub - function that subtruct the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_sub(stack_t **stack, unsigned int line_number)
{
	int a, b, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	b = (*stack)->n;
	a = (*stack)->next->n;
	result = a - b;

	do_pop(stack, line_number);

	(*stack)->n = result;
}


/**
 * do_div - function that dividthe first two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_div(stack_t **stack, unsigned int line_number)
{
	int a, b, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	b = (*stack)->n;
	a = (*stack)->next->n;
	if (b == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	result = a / b;

	do_pop(stack, line_number);

	(*stack)->n = result;
}


/**
 * do_mul - function that multiply the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_mul(stack_t **stack, unsigned int line_number)
{
	int a, b, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	b = (*stack)->n;
	a = (*stack)->next->n;
	result = a * b;

	do_pop(stack, line_number);

	(*stack)->n = result;
}
