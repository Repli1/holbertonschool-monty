#include "monty.h"

int _matcher(char **argv)
{
	stack_t **stack = malloc(sizeof(*stack));
	int i;
	char *dup, *token;

	*stack = NULL;
	for (i = 0; argv[i]; i++)
	{
		dup = strdup(argv[i]);
		if (dup == NULL)
			return (-1);
		token = strtok(dup, " \t");
		get_opcode_func(token)(stack, i + 1);
		free(dup);
	}
	/*aux = (*stack)->prev;
	while(aux != NULL)
	{
		aux = (*stack)->prev;
		free(*stack);
		*stack = aux;
	}*/
	free(stack);
	return (0);
}

void _push(stack_t **stack,__attribute__ ((unused)) unsigned int line_number)
{
	stack_t *aux, *temp;
	char *token;
	int i;

	temp = *stack;

	aux = malloc(sizeof(stack_t));
	token = strtok(NULL, " \t");
	if (_isnumber(token) == 0)
		i = atoi(token);
	if (aux == NULL)
		return;
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

	while(*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}

void (*get_opcode_func(char *s))(stack_t**, unsigned int)
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
	return (NULL);
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
