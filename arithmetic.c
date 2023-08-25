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
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	do_pop(stack, line_number);
	(*stack)->n += tmp;
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
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	do_pop(stack, line_number);
	(*stack)->n -= tmp;
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
	int tmp;

	if (!*stack || !(*stack)->next )
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	do_pop(stack, line_number);
	(*stack)->n /= tmp;
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
	int tmp;

	if (!*stack || !(*stack)->next )
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	do_pop(stack, line_number);
	(*stack)->n *= tmp;
}

/**
 * do_mod - function that return the remainder of the division
 * of two top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->n;
	do_pop(stack, line_number);
	(*stack)->n %= mod;
}
