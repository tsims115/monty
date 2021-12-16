#include "monty.h"
/**
 * pAll - prints all of the list
 * @stack: stack to use
 * @line_number: void in this function
 */
void pAll(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	( void ) line_number;
	int i = 0;

	while (node != NULL)
	{
		printf("node %d: %d\n", i,  node->n);
		node = node->next;
		i++;
	}
	return;
}
