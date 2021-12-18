#include "monty.h"
/**
 * splitter - takes the text from getline string and seperates each word
 * @fun: the string from getline
 * Return: an array of pointers to the individuals words
 */
char **splitter(char fun[])
{
	char **holder;
	int i = 0;
	long int length = strlen(fun) + 1;
	char *temp;

	holder = malloc(sizeof(char *) * (length * 2));

	temp = strtok(fun, " ");

	holder[i] = temp;
	while (temp != NULL)
	{
		i++;
		temp = strtok(NULL, " ");
		holder[i] = temp;
	}
	free(temp);

	return (holder);
}
