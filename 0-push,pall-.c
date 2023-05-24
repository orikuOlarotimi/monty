#include "monty.h"

/**
 * push_stack - pushes a value to a stack
 * @stack: a pointer to the top of a stack
 * @line_number: the current line number of the stack
 */

void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if ( i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		};
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		tail = (*stack)->next;
		new->prev = *stack;
		new->next = tail;
		if (tail)
			tail->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tail = *stack;
		while (tail->next)
			tail = tail->next;
		new->prev = tail;
		new->next = NULL;
		tail->next = new;
	}
}

