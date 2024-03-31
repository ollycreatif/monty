#ifndef MAIN_H
#define MAIN_H

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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

/*Type for opcode functions*/
typedef void (*op_func)(stack_t **, unsigned int);

/*File operations*/
void open_f(char *);
void read_f(FILE *);
int len_chars(FILE *);
int intprt_line(char *, int, int);
void find_func(char *, char *, int, int);

ssize_t getline(char **, size_t *, FILE *);

/*Stack operations*/
stack_t *cr8_node(int n);
void free_nodes(void);
void push_stk(stack_t **, unsigned int);
void pall_stk(stack_t **, unsigned int);
void add_2_queue(stack_t **, unsigned int);

void func_call(op_func, char *, char *, int, int);
void pint_top(stack_t **, unsigned int);
void pop_stk(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void _swap(stack_t **, unsigned int);

/*Math operations with nodes*/
void _add(stack_t **, unsigned int);

/*Error hanlding*/
void err_01(int error_code, ...);
void err_02(int error_code, ...);

#endif
