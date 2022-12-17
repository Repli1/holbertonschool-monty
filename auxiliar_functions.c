#include "monty.h"
/**
 * _matcher - tokenizes lines and sends them to get_opcode_func
 * @argv: array of lines to tokenize
 * Return: (0)
 */

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
		token = strtok(dup, " \n\t");
		if (token)
			get_opcode_func(token, i + 1)(&stack, i + 1);
		free(dup);
	}
	aux = stack;
	while (aux != NULL)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
	return (0);
}

/**
 * _push - pushes an element to the stack
 * @stack: pointer to doubly linked list
 * @line_number: line number
 */
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
	token = strtok(NULL, " \n\t");
	if (token && _isnumber(token) == 0)
		i = atoi(token);
	else
	{
		free(aux);
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
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

/**
 * _pall - prints all the elements in the stack
 * @stack: pointer to doubly linked list
 * @line_number: line number
 */
void _pall(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *aux = *stack;

	if (aux)
	{
		while (aux->next != NULL)
			aux = aux->next;
		while (aux != NULL)
		{
			printf("%d\n", aux->n);
			aux = aux->prev;
		}
	}
}

/**
 * get_opcode_func - compares a string to an opcode
 * @s: string to compare
 * @line_n: line number
 * Return: the corresponding function if succeds, (EXIT_FAILURE) if it fails
 */
void (*get_opcode_func(char *s, unsigned int line_n))(stack_t**, unsigned int)
{
	instruction_t opcodes[] = {
	{"push", _push},
	{"pall", _pall},
	{"swap", _swap},
	{"pint", _pint},	
	{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].opcode)
	{
		if (strcmp(s, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}

	fprintf(stderr, "L%i: unknown instruction %s\n", line_n, s);
	exit(EXIT_FAILURE);
}

/**
 * _isnumber - checks if the stirng is a number
 * @str: string to check
 * Return: (0) if succed, (-1) if it fails
 */
int _isnumber(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	for (; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]) == 0)
			return (-1);
	}
	return (0);
}
