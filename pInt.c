#include "monty.h"
/**
 * pInt - prints the first node of the stack
 * @stack: stack to use
 * @line_number: The line number to print if error occurs
 * Return: void
 */

void pInt(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (!stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", node->n);
}
