#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>


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

/**
 * struct line - values in the program.
 * @flag: could be queue or stack.
 * @cont: current line content.
 * @arg: the second value in current line.
 * @head: doubly linked list.
 * @file_des: file descriptor.
 * @_buffer: values.
 */
typedef struct line
{
	int flag;
	unsigned int cont;
	char *arg;
	stack_t *head;
	FILE *file_des;
	char *_buffer;
} line_t;

extern line_t global_v;

void _free(void);
void inital(FILE *file_des);
FILE *var_check(int argc, char *argv[]);
int _strcmp(char *s1, char *s2);
int searchs(char *str, char ch);
char *_strtoky(char *s, char *d);
void free_lists(stack_t *head);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int x);
void (*check_opcode(char *op))(stack_t **stack, unsigned int line_number);
void *_strcat(unsigned int num, unsigned int size);
void *_realloc(void *ptr, unsigned int size1, unsigned int size2);
void _push(stack_t **head, unsigned int line_num);
void _pall(stack_t **head, unsigned int line_num);
void _pint(stack_t **head, unsigned int line_num);
void _pop(stack_t **head, unsigned int line_num);
void _swap(stack_t **head, unsigned int line_num);
void _queue(stack_t **head, unsigned int line_num);
void _stack(stack_t **head, unsigned int line_num);
void _add(stack_t **head, unsigned int line_num);
void _nop(stack_t **head, unsigned int line_num);
void _sub(stack_t **head, unsigned int line_num);




#endif
