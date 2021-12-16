#include "monty.h"
/**
 * pAll - prints all of the list
 * @stack: stack to use
 * @line_number: void in this function
 */
void pAll(stackk_t **stack, unsigned int line_number)
{
	stackk_t *node = *stack;
	int i = 0;
	( void ) line_number;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
		i++;
	}
	return;
}
