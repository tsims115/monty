#include "monty.h"
/**
 * push - make a new node and add it to the beginning of the stack
 * @stack: stack to use
 * @line_number: number to put into new node
 * @str: string to get int number from
 */

void push(stack_t **stack, unsigned int line_number, char *str)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int n;
	int i = 0, c = 0;

	while (str[i])
	{
		if (!isdigit(str[i]))
			c++;
	        i++;
	}
	n = atoi(str);
	if (strcmp(str, "-0") == 0)
	{
		n = 0;
	}
	else if (c > 0 || !str || n == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = n;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
