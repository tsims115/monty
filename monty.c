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
	char *buf;
	char **argv;
	stackk_t *head;
	void (*funct)(stackk_t **stack, unsigned int line_number);

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	buf = malloc(sizeof(char) * 1000);
	if (buf == NULL)
	{
		free(buf);
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buf, sizeof(buf), file) != NULL)
	{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';
		argv = splitter(buf);
		funct = get_function(argv[0]);
		if (funct)
		{
			if (argv[1] == NULL)
				funct(&head, 0);
			else
				funct(&head, atoi(argv[1]));
		}
		else
		{
			fprintf(stderr, "L: unknown instruction %s",  argv[0]);
			free(buf);
			exit(EXIT_FAILURE);
		}
		free(argv);
	}
	fclose(file);
	return (0);
}

void(*get_function(char *s))(stackk_t **stack, unsigned int line_number)
{
	instruction_t functs[] = {
		{"push", push},
		{"pall", pAll},
		{"pint", pInt}
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
