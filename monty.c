#include "monty.h"
/**
 * main - interpret monty bytecodes from files
 * @ac: number of arguments
 * @av: The arguments themselves
 * Return: 0 if success or EXIT_FAILURE if fails
 */

int main(int ac, char **av)
{
	FILE *file;
	char *buf, *tmp;
	char **argv;
	stack_t *head = NULL;
	int line_number = 0;
	void (*funct)(stack_t **stack, unsigned int line_number);

	if (ac != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	buf = malloc(sizeof(char) * 1000);
	if (buf == NULL)
		free(buf), perror("Error: malloc failed\n"), exit(EXIT_FAILURE);
	file = fopen(av[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", av[1]), exit(EXIT_FAILURE);
	while (fgets(buf, sizeof(buf), file) != NULL)
	{
		tmp = strdup(buf);
		line_number++;
		if (tmp[strlen(tmp) - 1] == '\n')
			tmp[strlen(tmp) - 1] = '\0';
		printf("I am here: %d: %s\n", line_number, tmp);
		argv = splitter(tmp), funct = get_function(argv[0]);
		if (strcmp("push", argv[0]) == 0 && argv[1])
			push(&head, line_number, argv[1]);
		else if (funct)
			funct(&head, line_number);
		else
		{
			fprintf(stderr, "L: unknown instruction %s\n",  argv[0]), free(buf);
			exit(EXIT_FAILURE);
		}
		free(tmp);
		free(argv);
	}
	fclose(file);
	return (0);
}

/**
 * get_function - returns a function specified by instruction_t
 *
 * @s: The first argument passed as a string to perform
 * Return: A function pointer to the function to perform
 */
void(*get_function(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t functs[] = {
		{"pall", pAll},
		{"pint", pInt},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while (functs[i].opcode != NULL)
	{
		if (strcmp(s, functs[i].opcode) == 0)
		{
			return (functs[i].f);
		}
		i++;
	}
	return (NULL);
}
