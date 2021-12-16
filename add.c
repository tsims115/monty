#include "monty.h"
/**
 *
 *
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	unsigned int n = 0;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = node->n + (node->next)->n;
	node = *stack;
	*stack = node->next;
	free(node);
	(*stack)->n = n;

}
