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
	ssize_t line_size;
	size_t line_buf_size = 0;
	int line_number = 0;
	void (*funct)(stack_t **stack, unsigned int line_number);

	if (ac != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	buf = malloc(sizeof(char) * 10000);
	if (buf == NULL)
		free(buf), perror("Error: malloc failed\n"), exit(EXIT_FAILURE);
	file = fopen(av[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", av[1]), exit(EXIT_FAILURE);
	line_size = getline(&buf, &line_buf_size, file);
	while (line_size >= 0)
	{
		tmp = strdup(buf);
		line_number++;
		if (tmp[strlen(tmp) - 1] == '\n')
			tmp[strlen(tmp) - 1] = '\0';
		argv = splitter(tmp);
		funct = get_function(argv[0]);
		if (funct)
			funct(&head, line_number);
		else if (strcmp("push", argv[0]) == 0 && argv[1])
                        push(&head, line_number, argv[1]);
		else
		{
			fprintf(stderr, "L: unknown instruction %s\n",  argv[0]), free(buf);
			exit(EXIT_FAILURE);
		}
		free(tmp), free(argv);
		line_size = getline(&buf, &line_buf_size, file);
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

	if (s == NULL)
		return (functs[5].f);
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
