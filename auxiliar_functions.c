#include "monty.h"
#include <stddef.h>
#include <stdio.h>
/*int _getline(char **argv)
{
	int i;
	char *dup, *token;

	for (i = 0; argv[i]; i++)
	{
		dup = strdup(argv[i]);
		if (dup == NULL)
			return (-1);
		token = strtok(dup, " \t");
		while (token)
		{
			
		}
		free(dup);
	}
}*/

int _push(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		(*stack)->n = line_number;
	else
	{
		while(*stack != NULL)
			*stack = (*stack)->next;

		(*stack)->n = line_number;
		(*stack)->next = NULL;
		(*stack)->next->prev = *stack;
	}
	return (0);
}

int _pall(stack_t **stack,__attribute__ ((unused)) unsigned int line_number)
{

	while(*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	return (0);
}
