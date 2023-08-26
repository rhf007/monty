#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void file_open(char *filename);
int line_parse(char *buff, int line_num, int format);
void file_read(FILE *);
int len_chars(FILE *);
void find_function(char *, char *, int, int);

/*Stack operations*/
stack_t *node_create(int n);
void node_free(void);
void stack_print(stack_t **, unsigned int);
void stack_add(stack_t **, unsigned int);
void queue_add(stack_t **, unsigned int);

void call_function(op_func, char *, char *, int, int);

void top_print(stack_t **, unsigned int);
void top_pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void node_swap(stack_t **, unsigned int);

/*Math operations with nodes*/
void node_add(stack_t **, unsigned int);
void node_sub(stack_t **, unsigned int);
void node_div(stack_t **, unsigned int);
void node_mul(stack_t **, unsigned int);
void node_mod(stack_t **, unsigned int);

/*String operations*/
void char_print(stack_t **, unsigned int);
void str_print(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void check_error(int _error, ...);
void check_more_errors(int _error, ...);
void check_string_errors(int _error, ...);
void rotr(stack_t **, unsigned int);

#endif
