#include "monty.h"
/**
 * swap - swaps the first two elements in the stack
 * @stack: stack to use
 * @line_number: line number of the monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	stack_t *tmp;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = node->next;
	tmp->prev = NULL;
	node->next = tmp->next;
	tmp->next = node;
	node->prev = tmp;
	*stack = tmp;
	return;
}
