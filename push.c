#include "monty.h"
/**
 * push - make a new node and add it to the beginning of the stack
 * @stack: stack to use
 * @line_number: number to put into new node
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		perror("Error: malloc failed");
		free(new_node);
		return;
	}
	new_node->prev = NULL;
	new_node->n = line_number;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
        *stack = new_node;
	return;
}
