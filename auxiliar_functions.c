#include "monty.h"

int _matcher(char **argv)
{
	stack_t *stack = NULL, *aux;
	int i;
	char *dup, *token;

	for (i = 0; argv[i]; i++)
	{
		dup = strdup(argv[i]);
		if (dup == NULL)
			return (-1);
		token = strtok(dup, " \t");
		get_opcode_func(token, i + 1)(&stack, i + 1);
		free(dup);
	}
	aux = stack;
	while(aux != NULL)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
	return (0);
}

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *aux, *temp;
	char *token;
	int i;

	temp = *stack;

	aux = malloc(sizeof(stack_t));
	if (aux == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \t");
	if (token && _isnumber(token) == 0)
		i = atoi(token);
	else
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit (EXIT_FAILURE);
	}
	aux->n = i;
	aux->next = NULL;
	if (temp == NULL)
	{
		aux->prev = *stack;
		*stack = aux;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = aux;
		aux->prev = temp;
	}
}

void _pall(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *aux = *stack;

	while(aux->next != NULL)
	{
		aux = aux->next;
	}
	while(aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->prev;
	}
}

void (*get_opcode_func(char *s, unsigned int line_number))(stack_t**, unsigned int)
{
	instruction_t opcodes[] = {
	{"push", _push},
	{"pall", _pall},
	{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].opcode)
	{
		if (strcmp(s, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, s);
	exit (EXIT_FAILURE);
}

int _isnumber(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]) == 0)
			return (-1);
	}
	return (0);
}
