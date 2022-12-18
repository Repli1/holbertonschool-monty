#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: doubly linked list
 * @line_number: line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int x;

	temp = *stack;

	if ((temp == NULL) || (temp->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;

		x = temp->prev->n;
		temp->prev->n = temp->n;
		temp->n = x;
	}
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: doubly linked list
 * @line_number: line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		printf("%d\n", temp->n);
	}
}
/**
 * _pop - removes the top element of the stack
 * @stack: doubly linked list
 * @line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		if (temp->prev)
		{
			temp->prev->next = NULL;
			free(temp);
		}
		else
			temp = NULL;
	}
}
/**
 * _add - adds the top two elements of the stack
 * @stack: doubly linked list
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->prev->n = temp->prev->n + temp->n;
		_pop(stack, line_number);
	}
}
/**
 * _nop - does absolutely nothing!
 * @stack: doubly linked list
 * @line_number: line number
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	if (1 == 2)
	{
		printf("This function does nothingi%d", line_number);
		(*stack)->n = 0;
	}
}
