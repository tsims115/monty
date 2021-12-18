#include "monty.h"
/**
 * pop - remove first item of the stack
 * @stack: stack to use
 * @line_number: not used in this
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = node->next;
	free(node);
}
