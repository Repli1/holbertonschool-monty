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
