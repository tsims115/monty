#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct function - structure to find the correct function for a specifier
 * @spec: The specifier in question
 * @funct: The function associated with the specifier
 */
typedef struct function
{
	char *spec;
	int (*funct)(va_list *);
} function_t;
/**
 * struct path_list - structure build a linked list of PATH directories
 * @path: char * of path directory
 * @next: next node in linked list
 */
typedef struct path_list
{
	char *path;
	struct path_list *next;
} path_list;

char **splitter(char fun[]);

#endif
