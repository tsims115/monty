#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stackk_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stackk_t **stack, unsigned int line_number);
} instruction_t;

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
void (*get_function(char *s))(stackk_t **stack, unsigned int line_number);
void push(stackk_t **stack, unsigned int line_number);
void pAll(stackk_t **stack, unsigned int line_number);
void pInt(stackk_t **stack, unsigned int line_number);

#endif
