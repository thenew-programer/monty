#include "monty.h"

/**
 * _isdigit - checks for a digit
 * @str: string
 *
 * Return: 0 means NO digit, 1 means there IS digit
 */
int _isdigit(char *str)
{
	int i;

	if (str[0] == '-')
		i = 1;
	else
		i = 0;

	for (; str[i] != '\0'; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}

	return (1);
}
