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
	ssize_t n = 0;
	int i = 0;

	if (ac != 2)
	{
		perror("USAGE: monty file\n");
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
		for (i = 0; argv[i] != NULL; i++)
			printf("%s\n", argv[i]);
		free(argv);
	}
	fclose(file);
	return (0);
}
