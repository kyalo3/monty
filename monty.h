#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define BUFFERSIZE 1024
#define MAX_LINE_LENGTH 256
#define MAX_LINES 1000

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

extern char *value;

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
} stack_t;

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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void read_monty_file(const char *filename);
void execute_cmds(char *line, unsigned int line_number);
void handle_push(stack_t **head, unsigned int line_number);
void handle_pall(stack_t **head, unsigned int line_number);
void handle_pint(stack_t **head, unsigned int line_number);
void handle_swap(stack_t **head, unsigned int line_number);
void handle_pop(stack_t **head, unsigned int line_number);
void handle_mod(stack_t **head, unsigned int line_number);
void handle_add(stack_t **head, unsigned int line_number);
void handle_sub(stack_t **head, unsigned int line_number);
void handle_mul(stack_t **head, unsigned int line_number);
void handle_div(stack_t **head, unsigned int line_number);
void handle_nop(stack_t **head, unsigned int line_number);
void free_all(stack_t *head);
extern stack_t **stack;

#endif
